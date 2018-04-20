//#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>

#include "../inslib.h"
#include "config.h"

using namespace std;

int main(int argc, char *argv[]) {
    Session session(accessToken);

    cout << session.getUsersSelf();
    cout << session.getUsersSelfMediaRecent();
    cout << session.getMediaSearch(5000);
    cout << session.getMediaComments("1733142723563011958_4486674398");
    cout << session.getTagInfo("lol");
    cout << session.getTagRecentMedia("lol");
    cout << session.searchTag("lol");

    return 0;
}
