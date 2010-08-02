#include<iostream>
#include "boost/multi_array.hpp" //for entity inventory
#include "common_inclusions.h"
#include "game_int2str.h"
overlord Overlord;
namespace Game {
bool set_entity(entity*);
bool attack(short, short);
bool trade(short, short);
}
int main(void) {
    /*
    file_io * File = new file_io("test.txt");                   //creates object and handles save file "test.txt"

    File->file_load();                                          //first load file to use
    File->file_find("player", "", '0');                         //find the appropriate line
    File->file_write("player", '!', 'y', 0, 0, 0, 0, 0, 0, 0);  //zero out stats
    File->file_write("player", 'a', 'n', 255);                  //sets attack to 255
    std::cout << "Values At 0: " << File->values.at(1);         //returns location values is an vector storing temp stats
    File->values.clear();                                       //clears stats for next usage
    File->file_load();            //                              //loads another instance of test.txt
    entity * Entityzzz = new entity("hello");
    delete File;                                                //destructs the object
*/

    //For global items ; must
    entity * hellos = new entity("player000", 39, 22, 22, 22, 22, 22, 22, 22, 22);
    Game::set_entity(hellos); //0
    entity * TEST = new entity("test000", 229, 29, 33, 33, 22, 22, 22, 22, 22);
    Game::set_entity(TEST); //1


    TEST->add_currency(1000, 100, 100);
    TEST->update_curreny();

    Overlord.entity_list.at(0).set_attack(99); //set attack on entity 0 in vector
    Overlord.new_item(100, "sword", 20, false, 1, 2, 3, 4, 5, 6, 7, 99);
    std::cout << "name: " << Overlord.return_item_name(100, overlord::name) << std::endl;
    std::cout << "attack: " << Overlord.return_item_value(100, overlord::value) << std::endl;
    std::cout << Overlord.entity_list.at(0).rtrn_attack(); //return 0's at tack

return 0;

}
//POC for making new entity plus saves for
bool Game::set_entity(entity* x) {
Overlord.new_entity(x);
unsigned short i;
file_io Saves("main.txt");
const char * name = (char*)x->rtrn_name();
short location = x->rtrn_location();
bool alive = x->rtrn_alive();
short consecutive = x->rtrn_consecutive();
short chance2hit = x->rtrn_chance2hit();
short karma = x->rtrn_karma();
short health = x->rtrn_health();
short defense = x->rtrn_defense();
short attack = x->rtrn_attack();
short bronze = rand() % 100+1;
short silver = 0;
short gold = 0;
short platnium = 0;
static short ID = 0;
//static std::vector <std::string> loaded_entites(sizeof(short)); //there can only be that many entites since the vector is in a short
Saves.file_load();
Saves.file_find("player", "", 'n');
if (Saves.exists(name) == false) {
Saves.file_new_entity(name, location, alive, consecutive, chance2hit, karma, health, defense); //need to change the save files tomarrow
std::cout << std::endl << "not found" << std::endl;
}
else {
Saves.clear();
}
}

