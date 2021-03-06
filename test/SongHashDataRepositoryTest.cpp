#include <gtest/gtest.h>

#include "CustomSongInfo.h"
#include "SongHashDataRepository.h"
#include "SongHashDataRepositoryForTest.h"

TEST(SongHashDataRepositoryTest, ParseSuccess) {
    json testHashData = {
        {
            "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Beat Saber\\Beat Saber_Data\\CustomLevels\\16010 (Quicksand - Jabob, Narwhal, & Jez)",
            {
                { "directoryHash", 978644994890809 },
                { "songHash", "A4DC5CE503BE7D3E42DD9F51995A341BCFF36B30" }
            }
        },
        {
            "C:\\Program Files (x86)\\Steam\\steamapps\\common\\Beat Saber\\Beat Saber_Data\\CustomLevels\\9B20 (Wait For It - Hamilton - KashaCat)",
            {
                { "directoryHash", -297721919550886 },
                { "songHash", "E73F138A68CDE7A8D463189D2CE87B01F4BFE8E1" }
            }
        }
    };
    SongHashDataRepository* repo = new SongHashDataRepositoryForTest(testHashData);
    std::vector<CustomSongInfo> customSongs = repo->getSongHashData();
    EXPECT_EQ(2, customSongs.size());
    EXPECT_EQ("16010 (Quicksand - Jabob, Narwhal, & Jez)", customSongs.at(0).getSongName());
    EXPECT_EQ("A4DC5CE503BE7D3E42DD9F51995A341BCFF36B30", customSongs.at(0).getSongHash());
    EXPECT_EQ("9B20 (Wait For It - Hamilton - KashaCat)", customSongs.at(1).getSongName());
    EXPECT_EQ("E73F138A68CDE7A8D463189D2CE87B01F4BFE8E1", customSongs.at(1).getSongHash());
}

TEST(SongHashDataRepositoryTest, ParseBadJsonFail) {
    json testHashData = {
        "path", {
            { "unrelated_data_others_missing", "foo" }
        }
    };
    SongHashDataRepository* repo = new SongHashDataRepositoryForTest(testHashData);
    EXPECT_ANY_THROW(std::vector<CustomSongInfo> songs = repo->getSongHashData());
}
