#include <fstream>
#include <iostream>

#include "SongHashDataRepository.h"

SongHashDataRepository::SongHashDataRepository(fs::path beatSaberRootPath) {
    fs::path songCorePath = beatSaberRootPath / "UserData" / "SongCore";
    _hashDataFilePath = songCorePath / "SongHashData.dat";
}

std::vector<CustomSongInfo> SongHashDataRepository::getSongHashData() {
    return parseSongHashData(readSongHashData());
}

json SongHashDataRepository::readSongHashData() {
    std::ifstream hashDataInput(_hashDataFilePath);
    json hashData;
    hashDataInput >> hashData;
    return hashData;
}

std::vector<CustomSongInfo> SongHashDataRepository::parseSongHashData(json songHashData) {
    std::vector<CustomSongInfo> customSongs;
    for (auto& [songDirectory, rawInfo] : songHashData.items()) {
        CustomSongInfo songInfo = CustomSongInfo(
            rawInfo["directoryHash"],
            rawInfo["songHash"],
            songDirectory
        );
        std::cout << songInfo.toString() << "\n";
        customSongs.push_back(songInfo);
    }
    return customSongs;
}