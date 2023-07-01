#include <curl/curl.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <Url.hpp>
#include <HttpStatus.hpp>
#include <RestClient.hpp>
#include <ResponseEntity.hpp>

int main(int argc, char const *argv[])
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

    // TO DO: Especificar ContentType na chamada da função
    responseEntity = restClient->post(url, formData, headers);

    nlohmann::json data = responseEntity->getBody();

    std::cout << data["access_token"] << std::endl;
    std::cout << data["token_type"] << std::endl;

    return 0;
}
