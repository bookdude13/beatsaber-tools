#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>

namespace fs = std::filesystem;
using json = nlohmann::json;

class CustomSongInfo {
    private:
    int64_t _directoryHash;
    std::string _songHash;
    fs::path _rootDirectory;
    std::string _songName;

    public:
    CustomSongInfo(uint64_t directoryHash, std::string songHash, std::string rootDirectory) {
        _directoryHash = directoryHash;
        _songHash = songHash;
        _rootDirectory = fs::path(rootDirectory).make_preferred();

        // TODO figure out how to extract using fs::path directly. WSL is being weird.
        auto lastSep = rootDirectory.find_last_of("\\");
        _songName = rootDirectory.substr(lastSep + 1);
    }

    std::string printValue() { 
        return _songName + ": " + _songHash + ", " + std::to_string(_directoryHash);
    }
};

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

json getSongHashData(fs::path hashDataFilePath) {
    std::ifstream hashDataInput(hashDataFilePath);
    json hashData;
    hashDataInput >> hashData;
    return hashData;
}

int main() {
    std::cout << "Starting...\n";

    fs::path beatSaberPath = "/mnt/c/Program Files (x86)/Steam/steamapps/common/Beat Saber";

    fs::path songCorePath = beatSaberPath / "UserData" / "SongCore";
    fs::path hashDataFilePath = songCorePath / "SongHashData.dat";
    json hashData = getSongHashData(hashDataFilePath);

    for (auto& [songDirectory, rawInfo] : hashData.items()) {
        CustomSongInfo songInfo = CustomSongInfo(
            rawInfo["directoryHash"],
            rawInfo["songHash"],
            songDirectory
        );
        std::cout << songInfo.printValue() << "\n";
    }

    std::cout << "Done.\n";
    return 0;
}
