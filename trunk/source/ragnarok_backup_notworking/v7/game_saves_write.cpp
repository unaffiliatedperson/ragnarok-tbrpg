#include "game_saves.hpp"
#include "game_int2str.h"

bool file_io::file_write(const char * name, char option, char option_n, const short location, const short health,
        const short defense, const short attack, const short karma,
        const long gold, const bool alive) {

    std::cout << "size of vector " << file_info.size() << std::endl;


    char * file_name = File_name;
    std::ofstream file_out;
    short line = -1, i = 0;
    std::string data;

    if ((has_ran == true) && (file_info.size() > 0)) {

        while (i < file_info.size()) {
            if (file_info.at(i).find(name) < 999) {
                line = i;
                break;
            }
            ++i;
        }

        if (line != -1) {

            std::string stats[8] = {name, int2str(location), int2str(health), int2str(defense), int2str(attack), int2str(karma), int2str(gold), int2str(alive)};
            file_info.at(line) = "";

            if (option_n == 'n') {
                for (i = 0; i < 8; ++i) {
                    stats[i] = values.at(i);
                    if (option == 'l') {
                        stats[1] = int2str(location);
                    } else if (option == 'h') {
                        stats[2] = int2str(location);
                    } else if (option == 'd') {
                        stats[3] = int2str(location);
                    } else if (option == 'a') {
                        stats[4] = int2str(location);
                    } else if (option == 'k') {
                        stats[5] = int2str(location);
                    } else if (option == 'g') {
                        stats[6] = int2str(location);
                    } else if (option == 'A') {
                        stats[7] = int2str(location);
                    }
                    file_info.at(line) += stats[i] + ":";
                    std::cout << "values " << stats[i] << std::endl;
                }
            }
            if (option_n == 'y') {
                for (i = 0; i < 8; ++i) {
                    file_info.at(line) += stats[i] + ":";
                }
            }



            std::cout << "file_info.at(" << line << ") " << file_info.at(line) << std::endl;
            file_out.open(file_name, std::ios::out | std::ios::trunc);

            i = 0;
            while (file_info.size() > i) {
                std::cout << "there" << std::endl;
                file_out << file_info.at(i) << std::endl;
                ++i;
            }

            return true;
        } else return false;
    }
}
