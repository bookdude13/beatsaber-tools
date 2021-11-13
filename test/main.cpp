#include <gtest/gtest.h>

#include "CustomSongInfo.h"
#include "SongHashDataRepository.h"

TEST(HashData, ParseSuccess) {
    SongHashDataRepository repo = SongHashDataRepository("");
    json testHashData = {};
    std::vector<CustomSongInfo> customSongs = repo.parseSongHashData(testHashData);
    EXPECT_EQ(0, customSongs.size());
}