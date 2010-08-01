#include "game_saves.hpp"
#include "game_int2str.h"
bool file_io::file_new_entity(const char * name, const short location, const short health,
        const short defense, const short attack, const short karma,
        const long gold, const bool alive) {
    std::string stats[8] = {name, int2str(location), int2str(health), int2str(defense), int2str(attack), int2str(karma), int2str(gold), int2str(alive)};
    std::ofstream file_out;
    const char * file_name = File_name;
    int i;
    file_info.at(0) = "";
    if (file_info.size() > 0) {
    for (i = 0; i < 8; ++i) {
        file_info.at(0) += stats[i] + ":";
    }
    file_out.open(file_name, std::ios::out | std::ios::app);
    if (file_out.is_open()) {
        file_out << file_info.at(0);
        return true;
    }
    } else return false;
}

