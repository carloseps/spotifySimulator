#if !defined(PLAYLIST_DAO_HPP)
#define PLAYLIST_DAO_HPP

#include <Playlist.h>
#include <Track.h>
#include <sqlite3/sqlite3.h>
#include <SpotifyApiService.hpp>
#include <iostream>
#include <chrono>
#include <ctime>

class PlaylistDao
{
private:
  sqlite3 *db;

public:
  PlaylistDao();
  ~PlaylistDao();

  std::vector<Track> getTracks(int trackListId);
  Playlist *getPlaylistByName(std::string);
  std::vector<Playlist> getPlaylistsByUser(User user);
};

PlaylistDao::PlaylistDao() {}
PlaylistDao::~PlaylistDao() {}

std::vector<Track> PlaylistDao::getTracks(int trackListId)
{
  std::vector<Track> tracks;
  Playlist *result = nullptr;

  std::string query = "SELECT * "
                      "FROM Track "
                      "INNER JOIN TrackList_Track ON Tracks.id = TrackList_Track.track_id "
                      "WHERE TrackLists.tracklist_id = ?";

  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

  if (rc != SQLITE_OK)
  {
    // Handle query preparation error
  }

  sqlite3_bind_int(stmt, 1, trackListId);

  while (sqlite3_step(stmt) < SQLITE_ROW)
  {
    std::string spotifyId(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));

    SpotifyApiService spotifyApiService;

    Track *track = new Track();

    Track *track = spotifyApiService.getTrack(spotifyId);

    if (track != nullptr)
    {
      tracks.push_back(*track);
    }
  }

  sqlite3_finalize(stmt);

  return tracks;
}

Playlist *PlaylistDao::getPlaylistByName(std::string name)
{
  Playlist *result = new Playlist();

  std::string query = "SELECT * "
                      "FROM Playlist "
                      "INNER JOIN TrackLists ON Playlist.tracklist_id = TrackLists.id "
                      "INNER JOIN Users ON Playlist.playlist_owner = Users.id "
                      "WHERE TrackLists.tracklist_name = ?";

  sqlite3_stmt *stmt;
  int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
  if (rc != SQLITE_OK)
  {
    // Handle query preparation error
  }

  sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

  if (sqlite3_step(stmt) == SQLITE_ROW)
  {
    int id = sqlite3_column_int(stmt, 0);
    int trackListId = sqlite3_column_int(stmt, 1);
    std::string playlistName(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6)));
    std::string dateString(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));

    User user;
    user.setId(sqlite3_column_int(stmt, 2));
    user.setUsername(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 8)));
    user.setEmail(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 9)));
    user.setPassword(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 10)));

    std::vector<Track> tracks = getTracks(trackListId);

    // Create Playlist object and assign it to the result pointer
    result = new Playlist(id, playlistName, tracks, user, PrivacyState::PUBLIC);
  }

  sqlite3_finalize(stmt);

  return result;
};

#endif // PLAYLIST_DAO_HPP
