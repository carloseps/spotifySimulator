#include <curl/curl.h>
#include <iostream>
#include <sstream>
#include <nlohmann/json.hpp>
#include <Url.hpp>
#include <HttpStatus.hpp>
#include <RestClient.hpp>
#include <ResponseEntity.hpp>

int main(int argc, char const *argv[])
{
    RestClient *restClient = new RestClient();
    std::string tokenUrl = "https://accounts.spotify.com/api/token";
    ResponseEntity<nlohmann::json> *postResponseEntity;

    std::map<std::string, std::string> formData;
    formData["client_id"] = "d793a5bbf03749b1a5454ac339001842";
    formData["client_secret"] = "a99de5dfd02849f99db916b7679375fc";
    formData["grant_type"] = "client_credentials";

    std::map<std::string, std::string> headers;
    headers["Content-Type"] = "application/x-www-form-urlencoded";

    // TO DO: Especificar ContentType na chamada da função
    postResponseEntity = restClient->post(tokenUrl, formData, headers);

    nlohmann::json token = postResponseEntity->getBody();

    std::cout << token["access_token"].get<std::string>() << std::endl;
    std::cout << token["token_type"].get<std::string>() << std::endl;

    std::string getTrackUrl = "https://api.spotify.com/v1/tracks/11dFghVXANMlKmJXsNCbNl";

    ResponseEntity<nlohmann::json> *getResponseEntity;

    headers.erase("Content-Type");

    std::ostringstream oStringStream;
    oStringStream << token["token_type"].get<std::string>() << " " << token["access_token"].get<std::string>();
    headers["Authorization"] = oStringStream.str();

    std::cout << oStringStream.str() << std::endl;

    getResponseEntity = restClient->get(getTrackUrl, headers);
    nlohmann::json data = getResponseEntity->getBody();

    std::cout << data << std::endl;

    return 0;
}
