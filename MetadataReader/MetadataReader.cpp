// MetadataReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AudioTrack.h"

int main()
{
    AudioTrack     track ("Imagine", "John Lennon", "Imagine",   "Rock", "1971");
    MetadataFilter filter("Imagine", "John Lennon", "Imagine 2", "Rock", "1972");

    filter.setTitlePart(true);
    filter.setArtistPart(true);
    filter.setAlbumPart(true);
    filter.setGenrePart(true);
    filter.setYearPart(true);

    if (filter == track) {
        std::cout << "filter == track" << std::endl;
    } else {
        std::cout << "filter != track" << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
