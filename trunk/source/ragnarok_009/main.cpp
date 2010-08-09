#include<iostream>
#include "boost/multi_array.hpp" //for entity inventory
#include "common_inclusions.h"
#include "game_int2str.h"
///TODO
///Use Overlord to hold global_locations then use local variables in entity to determine location from
///Overlord. Like Overlord->set_location(0, 22);


namespace Game {
overlord Overlord;
bool set_entity(entity*); //need to do in overlord
//void give_item(entity*, short IDx); Done in overlord
bool load_entity_stats(short); //need to do in overlord
//bool attack(short, short); //Done in overlord
bool trade(short, short); //need to do in overlord
void banner();
bool playing=true;
}

int main(void) {
std::string user_input;

//Game::Overlord.new_item(66, "Sword", 771, false, 20, 20, 20, 20 , 20, 20, 22, 100);
//Game::Overlord.new_item(11, "The Altar", 777, false, 2002, 2002, 2002, 2002, 2002, 20, 22, 30002);
//Game::Overlord.new_item(4, "Underwear", 777, false, 0, 0, 0, 0, 0, 0, 0);
//Game::Overlord.new_item(10, "Trade Item", 777, false, 0, 0, 0,0,0,0,0);
entity * player = new entity("player", 100, 100, 100, 100, 60, 20, 20, 9999);
entity * goblin = new entity("goblin", 100, 100, 100, 100, 10, 100, 100, 10);
Game::Overlord.new_entity(player);
Game::Overlord.new_entity(goblin);
item *Sword = new item("sword", 0, true);
Game::Overlord.entity_list.at(0).add_inventory(Sword);

//Game::Overlord.give_entity_item(1, 111); //should give golbin item 111
//Game::Overlord.give_entity_item(1, 667); //should give golbin item 667
//Game::Overlord.give_entity_item(0, 4);   //should give player item 4
//Game::Overlord.give_entity_item(0, 10);  //should give player item 10

/*
player->add_inventory(2, "s", 0, 0, 0, 0,0);
player->display_inventory();
std::cout << std::endl;
goblin->display_inventory();

*/

//Game::Overlord.trade(1, 0, 10);
//std::cout << "Look " << Game::Overlord.return_item_name(667, overlord::name);
//std::cout << std::endl << "Value " << Game::Overlord.return_item_value(667, overlord::value);
//player->inventory_remove(111);

//std::cout << "from player " << player->inventory_name_return(667) << std::endl;
//std::cout << "from player " << player->return_item_value(667, entity::location);

///main loop
Game::banner();
while (Game::playing) {
std::cout << "-> ";
if (Game::Overlord.get_input() == false) {Game::playing = false; Game::banner();}  //get_input handles the game function calls

}

}





/*NOT NEEDED ONLY FOR REFERENCE NOW, GOING TO BE USING OVERLORD!*/
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
void Game::banner() {
    if (Game::playing == false) {std::cout << std::endl;}
std::cout << "\/ Ragnarok Pre-Alpha 0.2.7 \\" << std::endl << "\\      coded by cipher     /" << std::endl << " \\ report all bugs please /" << std::endl;
}
/*void Game::give_item(entity*x, short IDx) {
 std::string name = (std::string)Game::Overlord.return_item_name(IDx, overlord::name);
 x->add_inventory(100, "sword", 200, 0, 0, 0, 0, 0, 0);

}*/
///EXAMPLE CODE FOR SAVES ///*
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
*//*

    //For global items ; must
    entity * player = new entity("player000", 39, 22, 22, 22, 22, 22, 22, 22, 22);
    Game::set_entity(player); //0
    entity * TEST = new entity("test000", 229, 29, 33, 33, 22, 22, 22, 22, 22);
    Game::set_entity(TEST); //1
        Game::Overlord.new_item(100, "sword", 20, false, 1, 2, 3, 4, 5, 6, 7, 99);
    Game::Overlord.give_entity_item(0, 100);
    TEST->inventory_name_return(666);
    std::cout << "TEST CASE: " << TEST->inventory_name_return(666);
    TEST->add_currency(1000, 100, 100);
    TEST->update_curreny();

    Game::Overlord.entity_list.at(0).set_attack(99); //set attack on entity 0 in vector

    std::cout << "name: " << Game::Overlord.return_item_name(100, overlord::name) << std::endl;
    std::cout << "attack: " << Game::Overlord.return_item_value(100, overlord::value) << std::endl;
    std::cout << Game::Overlord.entity_list.at(0).rtrn_attack(); //return 0's at tack

return 0;

}*/
