cmake_minimum_required(VERSION 3.5)
project(mht)

## Build flags ##
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#include_directories(mht/include)

add_library(${PROJECT_NAME}
        mht/src/apqueue.cpp
        mht/src/assign.cpp
        mht/src/bassign.cpp
        mht/src/except.cpp
        mht/src/links.cpp
        mht/src/list.cpp
        mht/src/matrix.cpp
        mht/src/mdlmht.cpp
        mht/src/mht.cpp
        mht/src/mht_group.cpp
        mht/src/mht_report.cpp
        mht/src/mht_track.cpp
        mht/src/pqueue.cpp
        mht/src/tree.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC mht/include)

include_directories(tracking)

add_executable(track_corners
        tracking/track_corners.cpp
        tracking/motion_model.cpp)

target_link_libraries(track_corners
        ${PROJECT_NAME})

include_directories(libimage)

add_library(libimage
        libimage/close.c
        libimage/filbuf.c
        libimage/flsbuf.c
        libimage/name.c
        libimage/open.c
        libimage/pix.c
        libimage/rdwr.c
        libimage/rle.c
        libimage/row.c)

add_executable(draw_tracks
        tracking/drawTracks/drawTracks.c
        tracking/drawTracks/Xbulletin.c
        tracking/drawTracks/Xlist.c
        tracking/drawTracks/Xpush.c
        tracking/drawTracks/Xstring.c
        tracking/drawTracks/Xtoggle.c)

target_link_libraries(draw_tracks
        Xm Xt X11 libimage)