#include "game_saves.hpp"
std::string file_io::file_find(const char find[], const std::string entity, const char option, const unsigned int inventory) {
    if (has_ran) {
        values.clear();
        switch (file_info.size()) {
            case 0:
                std::cerr << "vector did not get filled propely" << std::endl;
                break;
            default:
                unsigned int i;
                //unsigned int x = 0;
                std::string temp;
                std::string tmp;
                unsigned position[3]; //line is 0, pos is 1
                for (i = 0; i < file_info.size(); ++i) {
                    if (file_info.at(i).find(find) < 999) {
                        position[0] = file_info.at(i).find(find); //the number @ it starts
                        position[1] = i; //the line number
                        temp = file_info.at(i).c_str();
                        std::cout << temp << std::endl;
                    }
                }

                std::istringstream bufferss(temp);
                i = 0;
                while (getline(bufferss, tmp, ':')) {
                    values.push_back(tmp);
                    std::cout << values.at(i) << std::endl;
                    ++i;
                }
                break;
        }; //(const char * name, short location = 0, short health = 100, short defense = 7, short attack = 10, short karma = 3, long gold = 200, bool alive = true)
        switch (option) {
            case 'n':
                    return values.at(0);
                break;
            case 'l':
                if (values.size() >= 1) {
                    return values.at(1);
                } else return "error, oob";
                break;
            case 'h':
                if (values.size() >= 2) {
                    return values.at(2);
                } else return "error, oob";
                break;
            case 'd':
                if (values.size() >= 3) {
                    return values.at(3);
                } else return "error, oob";
                break;
            case 'a':
                if (values.size() >= 4) {
                    return values.at(4);
                } else return "error, oob";
                break;
            case 'k':
                if (values.size() >= 5) {
                    return values.at(5);
                } else return "error, oob";
                break;
            case 'g':
                if (values.size() >= 6) {
                    return values.at(6);
                } else return "error, oob";
                break;
            case 'i':
                if (values.size() >= inventory) {
                    return values.at(inventory);
                } else return "error, oob";
                break;
            default:
                return "";
                break;
        };
    } else return "error, run file_load first!";
}

