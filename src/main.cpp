#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>

#include "CustomSongInfo.h"
#include "SongHashDataRepository.h"
#include "SongService.h"

namespace fs = std::filesystem;
using json = nlohmann::json;

// From https://stackoverflow.com/a/40903508
std::string readFile(fs::path path)
{
    // Open the stream to 'lock' the file.
    std::ifstream inFile(path, std::ios::in | std::ios::binary);

    // Obtain the size of the file.
    const auto size = fs::file_size(path);

    // Create a buffer.
    std::string result(size, '\0');

    // Read the whole file into the buffer.
    inFile.read(result.data(), size);

    return result;
}

int main() {
    std::cout << "Starting...\n";

    fs::path beatSaberPath = "/mnt/c/Program Files (x86)/Steam/steamapps/common/Beat Saber";

    SongHashDataRepository* songHashDataRepository = new SongHashDataRepository(beatSaberPath);
    SongService songService = SongService(songHashDataRepository);
    std::vector<CustomSongInfo> customSongs = songService.getSongs();

    std::cout << "Done.\n";
    return 0;
}
