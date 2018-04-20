//#define _GLIBCXX_USE_CXX11_ABI 0

#include <iostream>

#include "../inslib.h"
#include "config.h"

using namespace std;

int main(int argc, char *argv[]) {
    Session session(accessToken);

    cout << session.getUsersSelfMediaRecent();

    return 0;
}
