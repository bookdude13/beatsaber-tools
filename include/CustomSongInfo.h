#pragma once

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

class CustomSongInfo {
    private:
    int64_t _directoryHash;
    std::string _songHash;
    fs::path _rootDirectory;
    std::string _songName;

    public:
    CustomSongInfo(uint64_t directoryHash, std::string songHash, std::string rootDirectory);
    std::string printValue();
};
