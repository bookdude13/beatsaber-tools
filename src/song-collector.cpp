#include <fstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;


int main() {
    std::cout << "Starting...\n";

    fs::current_path(fs::temp_directory_path());
    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    fs::create_symlink("a", "sandbox/syma");
    for(auto& p: fs::recursive_directory_iterator("sandbox"))
        std::cout << p.path() << '\n';
    fs::remove_all("sandbox");

    std::cout << "Done.\n";
    return 0;
}
