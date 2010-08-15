#include "game_entities.h"
#include "game_overlord.hpp"
#include "string.h"
#include "game_item.h"
item::item(char*namex, unsigned short locationx, bool equiptx, unsigned char consecutivex, unsigned char chance2hitx, float karmax,
short healthx, short defensex, short valuex) {
 name = namex;
}

char * item::rtrn_name() {
 return (char*)name; //must change method entitely to use const
}

bool entity::inventory_remove(const char * name) {

short line = inventory.size() > 0 ? line = inventory_find(name) : line = -1;
//std::cout << line;

if (inventory_find(name) != -1) {
inventory.erase(inventory.begin() + line);
//std::cout << "invn_find = "<< inventory_find(name);
  return true;
 } else return false;
}
short entity::inventory_find(const char*namex) {

 bool found = false;
 short size_i = inventory.size() > 0 ? size_i = inventory.size() : size_i = -1;
 short i;
 if (size_i != -1) {
 for (i=0; i < size_i; ++i) {
     //std::cout << "inventory name at " << "\'" << i << "\' = " << "\'"<<inventory.at(i).name << "\'" << std::endl << "namex = " << "\'" << namex << "\'" << std::endl;
  if (strcmp(inventory.at(i).name, namex) == 0) {
      //std::cout << "found " << inventory.at(i).name;
      found = true;
      break;
      }
 }
 //std::cout << "found == " << "\'" << found << "\'" << std::endl;
 if (found == true) {
     //std::cout << "line: " << i;
      return i;
     }
     else return -1; //30 minutes worth of debugging :@
 }

else {
   // std::cout << "return -1";
 return -1;
}
}
void entity::add_inventory(item*x, bool hide) {
    bool continue_=true;
if (inventory.size() <= _item_amount) { inventory.push_back(*x);} else { continue_ = false;}
if (continue_ == false) {
if (hide != true) {std::cout << this->rtrn_name() << " has too many items!" << std::endl;}
} else { if (hide != true) {std::cout << this->rtrn_name() << " picked up a " << (*x).rtrn_name() << "!" << std::endl;}}
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
//std::cout << "sizeof(inventory) " << size_i << std::endl;
if (size_i > 0) {
for (i=0; i < size_i; ++i) {
if (inventory.at(i).name != "") {
std::cout << (char*)inventory.at(i).name << std::endl;
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
