/*
 * Project: Ragnorok tbRpg
 * Medium: Source Code, C++
 * Version:  0.4.5a (working, non-stable) [bounds checking still not working 100%, fix enum options]
 * Usage: See main function
 * License:
    <Programmed by cipher, this work is for an on going project called Ragnorok tbRpg>
    Copyright (C) <2010>  <cipher>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
//TODO: Add more error checking, stop out of bounds with vector! Add remove entity!
//TODO: Do something for inventory! Clean code, replace shitty code with better code!
//USAGE: file_write, the first arguemnt is the entity name, second is what to change, if third arguemnt is n it doesnt overwrite anything but
//USAGE: one that you specify on arugment 2. If it is y it will overwrite everything. always load, find, write, then clear. and new entity is the
//USAGE: same as the write, expect it appends to the file, and the two options are void in this one.
#ifndef GAME_SAVES_HPP_
   #define GAME_SAVES_HPP_
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class file_io {
public:

    bool has_ran;
    bool has_ran_write;
    char * File_name;
    std::vector<std::string> values;
    file_io(const char[]);
    ~file_io();
     bool file_load();
     std::string file_find(const char[], const std::string, const char, const unsigned int inventory = 0);
     bool file_write(const char * name = "default", char option = 'a', char option_n = 'n', const short location = 0, const short health = 100,
            const short defense = 5, const short attack = 5, const short karma = 3,
            const long gold = 0, const bool alive = true);

    bool file_new_entity(const char * name = "default", const short location = 0, const short health = 100,
            const short defense = 5, const short attack = 5, const short karma = 3,
            const long gold = 0, const bool alive = true);

private:
    std::vector <std::string> file_info;
};

#endif
