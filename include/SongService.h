#pragma once

#include <vector>
#include <nlohmann/json.hpp>
#include "CustomSongInfo.h"
#include "SongHashDataRepository.h"

using json = nlohmann::json;

class SongService {
    private:
        SongHashDataRepository* _repo;
    public:
        SongService(SongHashDataRepository* repo);
        std::vector<CustomSongInfo> getSongs();
};
