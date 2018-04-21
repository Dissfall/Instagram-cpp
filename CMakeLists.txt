cmake_minimum_required(VERSION 3.0)
project(inslib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)


message(STATUS "Looking for CURL")
include(FindCURL)
find_package(CURL REQUIRED)
if(CURL_FOUND)
    message(STATUS "Found CURL version: ${CURL_VERSION_STRING}")
    message(STATUS "Using CURL include dir(s): ${CURL_INCLUDE_DIRS}")
    message(STATUS "Using CURL lib(s): ${CURL_LIBRARIES}")
else()
    message(FATAL_ERROR "Could not find CURL")
endif()

message(STATUS "Looking for CURLPP")
find_library(CURLPP curlpp)
if(NOT CURLPP)
    message(FATAL_ERROR "Could not find CURLPP")
else()
    message(STATUS "CURLPP founded")
endif()

add_library(${PROJECT_NAME} SHARED ./inslib.h ./inslib.cpp)

if(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
    set(LIB_INSTALL_PATH ${CMAKE_INSTALL_PREFIX}/lib/)
elseif(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    set(LIB_INSTALL_PATH /usr/lib/)
endif()

#enable_testing()
#
#if(BUILD_TESTING)
#    add_subdirectory(tests)
#endif()

install(TARGETS ${PROJECT_NAME} DESTINATION ${LIB_INSTALL_PATH})
find_path(LIB_INCLUDE_PATH string.h)
install(FILES inslib.h DESTINATION ${LIB_INCLUDE_PATH})

