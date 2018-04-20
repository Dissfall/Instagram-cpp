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

string Session::getUsersSelfRecentMedia() {
    string url;
    string address("/v1/users/self/media/recent/?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::searchAreaRecentMedia(double lat, double lng, int distance) {
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

string Session::searchAreaRecentMedia(int distance) {
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

string Session::getMediaComments(string mediaId) { // 1733142723563011958_4486674398
    string url;
    string address("/v1/media/"); address.append(mediaId); address.append("/comments?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::getTagInfo(string tagName) {
    string url;
    string address("/v1/tags/"); address.append(tagName); address.append("?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::getTagRecentMedia(string tagName) {
    string url;
    string address("/v1/tags/"); address.append(tagName); address.append("/media/recent/?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::searchTag(string tagName) {
    string url;
    string address("/v1/tags/search?q="); address.append(tagName); address.append("&access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::getLocationInfo(string locationId) {
    string url;
    string address("/v1/locations/"); address.append(locationId); address.append("?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::getLocationRecentMedia(string locationId) {
    string url;
    string address("/v1/locations/"); address.append(locationId); address.append("/media/recent?access_token=");

    url.append(host);
    url.append(address);

    url.append(accessToken);

    return sendRequest(url).get();
}

string Session::searchLocation(double lat, double lng) {
    string url;
    string address("/v1/locations/search?");

    url.append(host);
    url.append(address);

    url.append("lat="); url.append(to_string(lat));
    url.append("&lng="); url.append(to_string(lat));

    url.append("&access_token=");
    url.append(accessToken);

    return sendRequest(url).get();
}