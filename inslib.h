//
// Created by dissfall on 07.04.18.
//
//#define _GLIBCXX_USE_CXX11_ABI 0

#ifndef PROJECT_INSLIB_H
#define PROJECT_INSLIB_H

#include <string>
#include <sstream>
#include <iostream>
#include <future>
#include <thread>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>


namespace {
    const long MyPort = 80;
}

using namespace std;

class Session {
    string host = "api.instagram.com";
    string basePath = "/v1";
    string accessToken = "";
    string authorizeUrl = "https://api.instagram.com/oauth/authorize";

public:
    explicit Session(const std::string &token = "token");

    string getUsersSelf();
    string getUsersSelfMediaRecent();
    string getMediaSearch(double lat = 0, double lng = 0, int distance = 1000);
    string getMediaSearch(int distance = 1000);
    string getMediaComments(string mediaId);
    string getTagInfo(string tagName);
    string getTagRecentMedia(string tagName);
    string searchTag(string tagName);
    string getLocationInfo(string locationId);
    string getLocationRecentMedia(string locationId);
    string searchLocation(double lat, double lng);

private:
    future<string> sendRequest(const string &url, const string &body = "");

};

#endif //PROJECT_INSLIB_H
