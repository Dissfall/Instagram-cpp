//
// Created by dissfall on 07.04.18.
//
//#define _GLIBCXX_USE_CXX11_ABI 0

#include "inslib.h"

Session::Session(const std::string &token) {
    accessToken = token;
}

future<string> Session::sendRequest(const string &url, const string &body) {

    cout << "Sending request: " << url << endl;

    return async(launch::async,
        [](const string &url, const string &body) mutable {
            list<string> header;
            curlpp::Cleanup clean;
            curlpp::Easy easy;
            ostringstream response;

            header.emplace_back("Content-Type: application/json");

            easy.setOpt(new curlpp::options::Url(url));
            easy.setOpt(new curlpp::options::HttpHeader(header));
            easy.setOpt(new curlpp::options::PostFields(body));
            easy.setOpt(new curlpp::options::PostFieldSize(body.length()));
            easy.setOpt(new curlpp::options::WriteStream(&response));
            easy.setOpt(new curlpp::options::FollowLocation(true));

            easy.perform();

            return string(response.str());
        }, url, body);

}

string Session::getUsersSelf() {
    string url;
    string address("/v1/users/self/?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::getUsersSelfMediaRecent() {
    string url;
    string address("/v1/users/self/media/recent/?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::getMediaSearch(double lat, double lng, int distance) {
    string url;
    string address("/v1/media/search?");

    url.append(host);
    url.append(address);

    if (distance != 1000) {
        url.append("distance=");
        url.append(to_string(distance));
        url.append("&");
    }

    url.append("lag=");
    url.append(to_string(lat));

    url.append("&lng=");
    url.append(to_string(lng));

    url.append("&access_token=");
    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::getMediaSearch(int distance) {
    string url;
    string address("/v1/media/search?");

    url.append(host);
    url.append(address);

    url.append("distance=");
    url.append(to_string(distance));

    url.append("&access_token=");
    url.append(accessToken);

    return sendRequest(url).get();
}