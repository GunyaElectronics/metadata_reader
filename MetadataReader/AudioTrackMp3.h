#pragma once
#include "AudioTrack.h"

namespace AudioMetadata {
    class AudioTrackMp3 :
        public AudioTrack
    {
        std::string filePath;
        const char* pType = "mp3";
    public:
        AudioTrackMp3(const char* pPath)
        {
            filePath = pPath;
        }
    };
}