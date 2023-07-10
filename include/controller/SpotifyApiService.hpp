#if !defined(SPOTIFY_API_SERVICE_HPP)
#define SPOTIFY_API_SERVICE_HPP

#include <AuthenticationToken.h>
#include <RestClient.hpp>
#include <Track.h>

// TO DO: Finalizar método getTrack e implementar métodos: getArtist, getAlbum e search

class SpotifyApiService
{
private:
  AuthenticationToken *token;
  void validateToken();
  void authenticate();

public:
  SpotifyApiService();
  Track *getTrack(std::string);
};

SpotifyApiService::SpotifyApiService()
{
  this->token = nullptr;
}

void SpotifyApiService::validateToken()
{
  if (this->token == nullptr || this->token->isExpired())
  {
    authenticate();
  }
}

void SpotifyApiService::authenticate()
{
  RestClient *restClient = new RestClient();
  std::string url = "https://accounts.spotify.com/api/token";
  ResponseEntity<nlohmann::json> *responseEntity;

  std::map<std::string, std::string> formData;
  formData["client_id"] = "d793a5bbf03749b1a5454ac339001842";
  formData["client_secret"] = "a99de5dfd02849f99db916b7679375fc";
  formData["grant_type"] = "client_credentials";

  std::map<std::string, std::string> headers;
  headers["Content-Type"] = "application/x-www-form-urlencoded";

  responseEntity = restClient->post(url, formData, headers);

  nlohmann::json data = responseEntity->getBody();

  AuthenticationToken *token = new AuthenticationToken(
      data["access_token"].get<std::string>(),
      data["token_type"].get<std::string>(),
      data["expires_in"].get<long>());

  this->token = token;
}

Track *SpotifyApiService::getTrack(std::string id)
{
  Track *track = new Track();
  RestClient *restClient = new RestClient();
  std::string url = "https://api.spotify.com/v1/tracks/" + id;
  ResponseEntity<nlohmann::json> *responseEntity;

  this->validateToken();

  std::map<std::string, std::string> headers;
  headers["Authorization"] = "Bearer " + token->getAccessToken();

  responseEntity = restClient->get(url, headers);

  if (responseEntity->getStatus() == HttpStatus::OK)
  {
    nlohmann::json data = responseEntity->getBody();

    track->setName(data["name"].get<std::string>());
    track->setDuration(data["duration_ms"].get<long>());
  }

  return track;
}

#endif // SPOTIFY_API_SERVICE_HPP
