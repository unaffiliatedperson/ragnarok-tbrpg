#include "game_entities.h"
#include "game_overlord.hpp"
item::item(char*namex, unsigned short locationx, bool equiptx, unsigned char consecutivex, unsigned char chance2hitx, float karmax,
short healthx, short defensex, short valuex) {
 name = namex;

}

void entity::add_inventory(item*x) {
inventory.push_back(*x);
++_item_amount;
}

std::string entity::inventory_name_return(char * namex) { //can check if exists too, kills two birds with one stone
short i;
bool found=false;
const short size_i = inventory.size();
    if (size_i > 0) {
for (i=0; i < size_i; ++i) {
if (inventory.at(i).name == namex) {
    found = true;
std::cout << i;
    }
    if (found == true) {
     return namex;
    }else {return "";}
   }
  }
 //return entity_inventory_name.at(ID);
}
short entity::return_item_value(const short ID, options x) {
  switch(x) {
   /* case (location):
    return entity_inventory.at(ID).at(1);
    break;
    case (equipt):
    return entity_inventory.at(ID).at(2);
    break;
    case (consecutive):
    return entity_inventory.at(ID).at(3);
    break;
    case (chance2hit):
    return entity_inventory.at(ID).at(4);
    break;
    case (karma):
    return entity_inventory.at(ID).at(5);
    break;
    case (broken):
    return entity_inventory.at(ID).at(6);
    break;
    case (health):
    return entity_inventory.at(ID).at(7);
    break;
    case (defense):
    return entity_inventory.at(ID).at(8);
    break;
    case (attack):
    return entity_inventory.at(ID).at(9);
    break;
    case (value):
    return entity_inventory.at(ID).at(10);
    break;
    default:
    return -1;
    break;*/
  };
 }
bool entity::inventory_display() {
short i;
const short size_i = inventory.size();
std::cout << "sizeof(inventory) " << size_i << std::endl;
if (size_i > 0) {
for (i=0; i < size_i; ++i) {
if (inventory.at(i).name != "") {
std::cout << (char*)inventory.at(i).name;
    }
   }
  }
}

void entity::display_invn_test() {
    /*
    short i;
    for (i=0; i < entity_inventory.size();++i) {
        if (entity_inventory.at(i).at(1) != 0) {
         std::cout << entity_inventory.at(i).at(1) << std::endl;
        }
    }
    */
}
