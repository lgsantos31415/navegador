#include <iostream>
#include <regex>
#include <vector>
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "./libs/httplib.h"
#include "./parseHtml.cpp"

std::vector<std::vector<std::string>> request(const char* url) {
    httplib::SSLClient client(url);
    client.set_follow_location(true);

    auto response = client.Get("/");

    if (response) {
        std::string body = response->body;
        
        std::vector<std::vector<std::string>> result = parseHtml(body);
        return result;
    } else{
        return {};
    }
}