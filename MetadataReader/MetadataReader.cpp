// MetadataReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "AudioTrackMp3.h"

using namespace std;
using namespace AudioMetadata;

int main(int argc, char* pArgs[])
{
    AudioTrack     track ("Imagine", "John Lennon", "Imagine",   "Rock", "1971");
    MetadataFilter filter("Imagine", "John Lennon", "Imagine 2", "Rock", "1972");

    wcout << "Arguments counter = " << argc << endl;

    filter.setTitlePart(true);
    filter.setArtistPart(true);
    filter.setAlbumPart(true);
    filter.setGenrePart(true);
    filter.setYearPart(true);

    if (filter == track) {
        wcout << "filter == track" << std::endl;
    } else {
        wcout << "filter != track" << std::endl;
    }

    return 0;
}
