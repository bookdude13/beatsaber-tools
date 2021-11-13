#pragma once

#include <filesystem>
#include <vector>

#include <nlohmann/json.hpp>

#include "CustomSongInfo.h"

namespace fs = std::filesystem;
using json = nlohmann::json;

class SongHashDataRepository {
    private:
        fs::path _hashDataFilePath;
        std::vector<CustomSongInfo> parseSongHashData(json songHashData);
    protected:
        virtual json readSongHashData();
    public:
        SongHashDataRepository(fs::path beatSaberRootPath);
        std::vector<CustomSongInfo> getSongHashData();
};
