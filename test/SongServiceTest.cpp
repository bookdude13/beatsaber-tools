#include <gtest/gtest.h>

#include "CustomSongInfo.h"
#include "SongService.h"
#include "SongHashDataRepositoryForTest.h"

TEST(SongServiceTest, NoSongsSuccess) {
    SongHashDataRepository* repo = new SongHashDataRepositoryForTest({});
    SongService service = SongService(repo);
    std::vector<CustomSongInfo> songs = service.getSongs();
    EXPECT_EQ(0, songs.size());
}
