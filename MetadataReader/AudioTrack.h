#pragma once

#include <iostream>

class AudioTrack {
    std::string title;
    std::string artist;
    std::string album;
    std::string genre;
    std::string year;

public:
    AudioTrack()
    {
    }

    AudioTrack(const std::string& title, const std::string& artist,
        const std::string& album, const std::string& genre, const std::string& year) :
        title(title), artist(artist), album(album), genre(genre), year(year) 
    {
    }

    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getAlbum() const { return album; }
    std::string getGenre() const { return genre; }
    std::string getYear() const { return year; }

    void setTitle(const std::string& newTitle) { title = newTitle; }
    void setArtist(const std::string& newArtist) { artist = newArtist; }
    void setAlbum(const std::string& newAlbum) { album = newAlbum; }
    void setGenre(const std::string& newGenre) { genre = newGenre; }
    void setYear(const std::string& newYear) { year = newYear; }
};

class MetadataFilter {
public:
    MetadataFilter (const std::string& title, const std::string& artist,
        const std::string& album, const std::string& genre, const std::string& year);
    ~MetadataFilter ();

    bool operator==(const AudioTrack& audioTrack) const;
    bool operator!=(const AudioTrack& audioTrack) const {
        return !(*this == audioTrack);
    }

    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getAlbum() const { return album; }
    std::string getGenre() const { return genre; }
    std::string getYear() const { return year; }

    bool isTitlePart() const { return titlePart; }
    bool isArtistPart() const { return artistPart; }
    bool isAlbumPart() const { return albumPart; }
    bool isGenrePart() const { return genrePart; }
    bool isYearPart() const { return yearPart; }

    void setTitlePart(bool newTitlePart) { titlePart = newTitlePart; }
    void setArtistPart(bool newArtistPart) { artistPart = newArtistPart; }
    void setAlbumPart(bool newAlbumPart) { albumPart = newAlbumPart; }
    void setGenrePart(bool newGenrePart) { genrePart = newGenrePart; }
    void setYearPart(bool newYearPart) { yearPart = newYearPart; }

private:
    std::string title;
    std::string artist;
    std::string album;
    std::string genre;
    std::string year;

    bool titlePart = false;
    bool artistPart = false;
    bool albumPart = false;
    bool genrePart = false;
    bool yearPart = false;
};
