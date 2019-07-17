cmake_minimum_required(VERSION 3.5)
project(multi_hypothesis_tracker)

## Build flags ##
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(mht)
include_directories(tracking)

add_library(${PROJECT_NAME}
        mht/apqueue.cpp
        mht/assign.cpp
        mht/bassign.cpp
        mht/except.cpp
        mht/links.cpp
        mht/list.cpp
        mht/matrix.cpp
        mht/mdlmht.cpp
        mht/mht.cpp
        mht/mht_group.cpp
        mht/mht_report.cpp
        mht/mht_track.cpp
        mht/pqueue.cpp
        mht/tree.cpp)

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