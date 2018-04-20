/*
 *      Copyright 2018 George Lykuanov (dissfalling@gmail.com)
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

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
    string getUsersSelfRecentMedia();
    string searchAreaRecentMedia(double lat = 0, double lng = 0, int distance = 1000);
    string searchAreaRecentMedia(int distance = 1000);
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
