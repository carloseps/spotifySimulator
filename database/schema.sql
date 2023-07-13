CREATE TABLE IF NOT EXISTS Users (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    username VARCHAR(255) NOT NULL,
    email VARCHAR(255) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS Tracks (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    spotify_id VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE IF NOT EXISTS TrackLists (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    tracklist_name VARCHAR(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS TrackList_Track (
    tracklist_id INTEGER NOT NULL,
    track_id INTEGER NOT NULL,
    PRIMARY KEY(tracklist_id, track_id),
    FOREIGN KEY(tracklist_id) REFERENCES TrackList(id),
    FOREIGN KEY(track_id) REFERENCES Track(id)
);

CREATE TABLE IF NOT EXISTS Playlist (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    tracklist_id INTEGER NOT NULL,
    playlist_owner INTEGER NOT NULL,
    privacy_state TEXT CHECK(privacy_state IN ('PUBLIC','LISTEN_ONLY','PRIVATE')) DEFAULT 'PUBLIC' NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
    FOREIGN KEY(tracklist_id) REFERENCES TrackLists(id),
    FOREIGN KEY(playlist_owner) REFERENCES Users(id)
);

CREATE TABLE IF NOT EXISTS Album (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    tracklist_id INTEGER NOT NULL,
    author VARCHAR(255) NOT NULL,
    release_date TIMESTAMP NOT NULL,
    FOREIGN KEY(tracklist_id) REFERENCES TrackLists(id)
);
