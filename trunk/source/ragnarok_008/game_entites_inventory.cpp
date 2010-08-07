#include "game_entities.h"
#include "game_overlord.hpp"
   std::vector<std::vector<short> > entity_inventory ( 1000, std::vector<short> ( 11 ) );
   std::vector<std::string>  entity_inventory_name ( 1000 );
   short _list[1000];
void entity::add_inventory(short ID, const std::string namex, const unsigned short locationx, bool equipt, const unsigned char consecutivex,
   const unsigned char chance2hitx, const float karmax, const bool brokenx, const short healthx, const short defensex, const short attackx,
   const short valuex) {
entity_inventory_name.at(ID) = (std::string)namex;

entity_inventory.at(ID).at(0)  = ID;
entity_inventory.at(ID).at(1)  = locationx;
entity_inventory.at(ID).at(2)  = (short)equipt;
entity_inventory.at(ID).at(3)  = (short)consecutivex;
entity_inventory.at(ID).at(4)  = (short)chance2hitx;
entity_inventory.at(ID).at(5)  = (short)karmax;
entity_inventory.at(ID).at(6)  = (short)brokenx;
entity_inventory.at(ID).at(7)  = healthx;
entity_inventory.at(ID).at(8)  = defensex;
entity_inventory.at(ID).at(9)  = attackx;
entity_inventory.at(ID).at(10) = valuex;
}
std::string entity::inventory_name_return(short ID) {
 return entity_inventory_name.at(ID);
}
short entity::return_item_value(const short ID, options x) {
  switch(x) {
    case (location):
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
    break;
  };
 }
bool entity::inventory_remove(short ID) {
   short i;
   entity_inventory_name.at(ID) = "";
   for (i=1; i <= 10; ++i) {
    entity_inventory.at(ID).at(i) = 0;
   }
   entity_inventory.at(ID).at(1) = this->rtrn_location();
}

void entity::display_inventory() {
 for (int i=0; i < 1000; ++i){
     std::string temp;
     temp = entity_inventory_name.at(i);
     if (temp != "") {
         std::cout << temp << " | ID: " << i << std::endl;
         }
     }
}
void entity::display_invn_test() {
    short i;
    for (i=0; i < entity_inventory.size();++i) {
        if (entity_inventory.at(i).at(1) != 0) {
         std::cout << entity_inventory.at(i).at(1) << std::endl;
        }
    }
}
