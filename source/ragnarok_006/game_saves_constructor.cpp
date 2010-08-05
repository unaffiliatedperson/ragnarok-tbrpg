#include "game_saves.hpp"
file_io::file_io(const char file_name[]) {
    File_name = (char*) file_name;
    has_ran = false;
    has_ran_write = false;
    std::fstream f_handle(file_name, std::ios::in);
    if (f_handle.is_open()) {} else {f_handle.close(); f_handle.open(file_name, std::ios::out);}
}

