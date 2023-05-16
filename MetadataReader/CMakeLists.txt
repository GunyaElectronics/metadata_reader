cmake_minimum_required(VERSION 3.0.0)
project(MetadataReader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    AudioTrack.cpp
    AudioTrackMp3.cpp
    MetadataReader.cpp
)

add_executable(Metadata_Reader ${SOURCES})