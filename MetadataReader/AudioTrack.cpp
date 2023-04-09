#include "AudioTrack.h"

bool MetadataFilter::operator==(const AudioTrack& audioTrack) const {
    return (!titlePart || title == audioTrack.getTitle()) &&
        (!artistPart || artist == audioTrack.getArtist()) &&
        (!albumPart || album == audioTrack.getAlbum()) &&
        (!genrePart || genre == audioTrack.getGenre()) &&
        (!yearPart || year == audioTrack.getYear());
}

MetadataFilter::MetadataFilter()
{
}

MetadataFilter ::~MetadataFilter()
{
}