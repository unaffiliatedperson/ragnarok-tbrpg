#include "game_saves.hpp"
file_io::file_io(const char file_name[]) {
    File_name = (char*) file_name;
    has_ran = false;
    has_ran_write = false;
}
