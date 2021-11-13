#pragma once

#include "SongHashDataRepository.h"

class SongHashDataRepositoryForTest : public SongHashDataRepository {
    private:
        json _songHashData;
    protected:
        virtual json readSongHashData() override {
            return _songHashData;
        }
    public:
        SongHashDataRepositoryForTest(json songHashData) : SongHashDataRepository("test") {
            _songHashData = songHashData;
        }
};
