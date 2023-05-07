// MetadataReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#include <clocale>
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#include "AudioTrackMp3.h"

using namespace std;
using namespace AudioMetadata;

int main(int argc, char* pArgs[])
{
    AudioTrack     track ("Imagine", "John Lennon", "Imagine",   "Rock", "1971");
    MetadataFilter filter("Imagine", "John Lennon", "Imagine 2", "Rock", "1972");

    _setmode(_fileno(stdout), _O_U16TEXT);

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    wcout << "Arguments counter = " << argc << endl;

    for (int i = 0; i < argc; i++) {
        wcout << "Arg: " << pArgs[i] << endl;
    }

    size_t length;
    mbstowcs_s(&length, nullptr, 0, pArgs[1], 0);
    vector<wchar_t> wstr(length);
    mbstowcs_s(nullptr, wstr.data(), length, pArgs[1], length - 1);

    wstring path(wstr.data());

    wcout << "Path in arguments is '" << path << "'\n";

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

    ifstream file("D:\\song.mp3", std::ios::binary);

    if (!file) {
        wcout << "Fle not found" << endl;
    }

    file.close();

    string folderPath = pArgs[1];
    vector<std::wstring> mp3Files;
    int cnt = 1;
    try {
        for (const auto& entry : filesystem::directory_iterator(folderPath)) {
            if (entry.is_regular_file() && entry.path().extension() == ".mp3") {
                mp3Files.push_back(entry.path().wstring());
            }
        }
    }
    catch (const filesystem::filesystem_error& e) {
        wcerr << "Error: " << e.what() << endl;
    }

    wcout << "MP3 files list:" << endl;
    for (const auto& filname : mp3Files) {
        wcout << "File " << cnt++ << ": " << filname << endl;
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
