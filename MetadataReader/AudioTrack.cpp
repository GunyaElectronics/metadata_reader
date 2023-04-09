#include "AudioTrack.h"

bool MetadataFilter::operator==(const AudioTrack& audioTrack) const {
    return (!titlePart || title == audioTrack.getTitle()) &&
        (!artistPart || artist == audioTrack.getArtist()) &&
        (!albumPart || album == audioTrack.getAlbum()) &&
        (!genrePart || genre == audioTrack.getGenre()) &&
        (!yearPart || year == audioTrack.getYear());
}

MetadataFilter::MetadataFilter(const std::string& title, const std::string& artist,
    const std::string& album, const std::string& genre, const std::string& year) :
    title(title), artist(artist), album(album), genre(genre), year(year) 
{
}

MetadataFilter ::~MetadataFilter()
{
}