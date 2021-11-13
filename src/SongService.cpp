#include "SongService.h"

SongService::SongService(SongHashDataRepository* repo) : _repo(repo) {
}

std::vector<CustomSongInfo> SongService::getSongs() {
    std::vector<CustomSongInfo> songs = _repo->getSongHashData();
    return songs;
}
