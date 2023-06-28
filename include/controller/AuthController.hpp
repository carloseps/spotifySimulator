#if !defined(AUTH_CONTROLLER_HPP)
#define AUTH_CONTROLLER_HPP

#include <curl/curl.h>
#include "../../lib/nlohmann/json.hpp"
#include "../model/AuthenticationToken.hpp"
#include <iostream>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* response) {
  size_t totalSize = size * nmemb;
  response->append(static_cast<char*>(contents), totalSize);
  return totalSize;
}

class AuthController
{
private:
    AuthenticationToken *token;
public:
    AuthController() {};
    ~AuthController() {};

    void getToken()
    {
        // TO DO: checar se o token já expirou, caso sim, pegar um novo token
        if (token == nullptr)
        {
            CURL *curl = curl_easy_init();

            if (curl)
            {
                // Set the target URL
                curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/api/endpoint");

                // Set the request type to POST
                curl_easy_setopt(curl, CURLOPT_POST, 1L);

                // Create a map to store the form data
                std::map<std::string, std::string> formData;
                formData["client_id"] = "d793a5bbf03749b1a5454ac339001842";
                formData["client_secret"] = "a99de5dfd02849f99db916b7679375fc";
                formData["grant_type"] = "client_credentials";

                // Encode the form data
                std::string encodedData;
                for (const auto& pair : formData) {
                    if (!encodedData.empty()) {
                        encodedData += "&";
                    }
                    encodedData += pair.first + "=" + pair.second;
                }

                // Set the form data
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, encodedData.c_str());

                // Set the Content-Type header
                struct curl_slist *headers = NULL;
                headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

                // Set the response callback
                std::string responseData;
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);

                // Perform the request
                CURLcode res = curl_easy_perform(curl);

                // Check for errors
                if (res != CURLE_OK)
                {
                std::cerr << "cURL request failed: " << curl_easy_strerror(res) << std::endl;
                }

                // Parse the response as JSON
                nlohmann::json data = nlohmann::json::parse(responseData);

                std::cout << data["access_token"] << std::endl;
                std::cout << data["token_type"] << std::endl;

                // Process the JSON response
                // ...

                // Cleanup
                curl_easy_cleanup(curl);
                curl_slist_free_all(headers);
            }
        }
    }
};

#endif // AUTH_CONTROLLER_HPP
