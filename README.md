# Instagram C++ 
_The C++ library provides a simple interface for working with public Instagram API_

Requires
--------
  * curlpp
  * The library works according to the standard С++14 (С++11 tested)

Instagram REST and Search APIs
------------------------------
Documentation and last news the Instagram API you can find on [Instagram developer site](http://instagram.com/developer)

Blog
----
You can find me in social networks by username **_dissfall_**:
_(Vero, twitter, instagram...)_

Authentication
--------------
Library uses Instagram access token to provide functionality. How get access token you can find there: https://instagram.com/developer/authentication/

Example of use
--------------
```
#include <iostream>

#include "inslib.h"

using namespace std;

int main(int argc, char *argv[]) {
    Session session(YOUR_ACCESS_TOKEN);

    cout << session.getUsersSelf();

    return 0;
}
```

Endpoints
---------
_All endpoints resurns **string** type_

### Users

#### getUsersSelf()
Returns information about the owner of the _access_token_
https://instagram.com/developer/endpoints/users/#get_users_self

#### getUsersSelfRecentMedia()
Returns the most recent media published by the owner of the _access_token_
https://instagram.com/developer/endpoints/users/#get_users_media_recent_self

#### searchAreaRecentMedia(double lat = 0, double lng = 0, int distance = 1000) 
**_or_** searchAreaRecentMedia(int distance = 1000)
Returns result search for recent media in a given area
lat -- latitude of the center search coordinate
lng -- longitude of the center search coordinate
distance -- radius of searching area
https://instagram.com/developer/endpoints/media/#get_media_search

#### getMediaComments(_string_ mediaId)
Returns a list of recent comments on your media object
https://instagram.com/developer/endpoints/comments/#get_media_comments

#### getTagInfo(_string_ tagName)
Returns information about a tag object
https://instagram.com/developer/endpoints/tags/#get_tags

#### getTagRecentMedia(string tagName)
Returns a list of recently tagged media
https://instagram.com/developer/endpoints/tags/#get_tags_media_recent

#### searchTag(string tagName)
Returns result of searching tag by name
https://instagram.com/developer/endpoints/tags/#get_tags_search

#### getLocationInfo(string locationId)
Returns information about a location
https://instagram.com/developer/endpoints/locations/#get_locations

#### getLocationRecentMedia(string locationId)
Returns a list of recent media objects from a given location
https://instagram.com/developer/endpoints/locations/#get_locations_media_recent

#### searchLocation(double lat, double lng)
Returns result of searching for a location by geographic coordinate
https://instagram.com/developer/endpoints/locations/#get_locations_search

Contributing
------------
Here are some ways *you* can contribute:

  * by using alpha, beta, and prerelease versions
  * by support author on [patreon](https://www.patreon.com/dissfall)
  * by reporting bugs
  * by suggesting new features
  * by writing or editing documentation
  * by writing specifications
  * by writing code
  * by reviewing patches
