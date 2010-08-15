#include<iostream>
#include "boost/multi_array.hpp" //for entity inventory
#include "common_inclusions.h"
#include "game_int2str.h"
///Coded by cipher
///TODO
///Use Overlord to hold global_locations then use local variables in entity to determine location from
///Overlord. Like Overlord->set_location(0, 22); (not yet begun)
///try moving item class to overlord (done), but still conveting and writting new functions for it.
///store global items in maps (in progress)
///get maps working for item retreival (in progress)

namespace Game {
overlord Overlord;
bool set_entity(entity*); //need to do in overlord
bool load_entity_stats(short); //need to do in overlord
bool trade(short, short); //need to do in overlord
void banner();
bool playing=true;
}

using Game::Overlord;
int main(void) {
std::string user_input;
typedef std::map <std::string, item*> mymap;
mymap map;
entity * player = new entity("player", 100, 100, 100, 100, 60, 20, 20, 9999);
entity * goblin = new entity("goblin", 100, 100, 100, 100, 10, 100, 100, 10);
Game::Overlord.new_entity(player); //ID 0
Game::Overlord.new_entity(goblin); //ID 1
item *item_place_holder = new item("test_item", 0, false);
item *Sword = new item("sword", 99, true, 99, 99, 99, 99, 99, 99); //ID 0

item *Mace = new item("mace", 0, false);  //ID 1

map["sword"] = Sword;
map["Mace"] = Mace;
for (mymap::const_iterator iter = map.begin(); iter != map.end(); ++iter) {
//std::cout << iter->second->name << '-';
if (map.find("sword") != map.end()) {
  //std::cout << map.find("sword")->second->name << std::endl;
 }
}
Game::Overlord.new_item(item_place_holder);
Game::Overlord.entity_list.at(0).add_inventory(item_place_holder, true);
Game::Overlord.entity_list.at(0).add_inventory(Sword, true);
Game::Overlord.entity_list.at(0).add_inventory(Mace, true);
Game::Overlord.entity_list.at(0).add_inventory(Mace, true);
Game::Overlord.entity_list.at(0).add_inventory(Sword, true);
Game::Overlord.entity_list.at(0).add_inventory(Mace, true);
Game::Overlord.give_entity_item(0, 0); //Give Entity 0 item 0
Overlord.give_entity_item(0, 0);


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
std::cout << "\/ Ragnarök Pre-Alpha 0.2.9 \\" << std::endl << "\\      coded by cipher     /" << std::endl << " \\ report all bugs please /" << std::endl;
if (Game::playing == true) {std::cout << std::endl;}
}
