#include "CustomSongInfo.h"

CustomSongInfo::CustomSongInfo(uint64_t directoryHash, std::string songHash, std::string rootDirectory) {
    _directoryHash = directoryHash;
    _songHash = songHash;
    _rootDirectory = fs::path(rootDirectory).make_preferred();

    // TODO figure out how to extract using fs::path directly. WSL is being weird.
    auto lastSep = rootDirectory.find_last_of("\\");
    _songName = rootDirectory.substr(lastSep + 1);
}

std::string CustomSongInfo::printValue() { 
    return _songName + ": " + _songHash + ", " + std::to_string(_directoryHash);
}
