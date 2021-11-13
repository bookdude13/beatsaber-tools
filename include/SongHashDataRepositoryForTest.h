#pragma once

#include "SongHashDataRepository.h"

class SongHashDataRepositoryForTest : public SongHashDataRepository {
    private:
        json _songHashData;
    protected:
        virtual json readSongHashData() override;
    public:
        SongHashDataRepositoryForTest(json songHashData);
};

SongHashDataRepositoryForTest::SongHashDataRepositoryForTest(json songHashData) : SongHashDataRepository("") {
    _songHashData = songHashData;
}

// Override
json SongHashDataRepositoryForTest::readSongHashData() {
    std::cout << "for test" << "\n";
    return _songHashData;
}
