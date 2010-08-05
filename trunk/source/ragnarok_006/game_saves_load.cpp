#include "game_saves.hpp"
bool file_io::file_load() {
    const char * file_name = File_name;
    short line = 0;
    if (has_ran) {
        file_info.clear();
    }
    std::string local_buffer;
    std::ifstream file_in(file_name, std::ios::in | std::ios::binary);

    if (file_in.is_open()) {
        while (getline(file_in, local_buffer)) {
            file_info.push_back(local_buffer);
           // std::cout << file_info.at(line) << std::endl;
            ++line;
        }
        has_ran = true;
        return true;
    } else {
        std::cerr << "file_io error, could not open" << std::endl;
        has_ran = true;
        return false;
    }
}
