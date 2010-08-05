#include "game_overlord.hpp"
#include "game_int2str.h"
//will assume it really exists :O
std::vector<std::vector<short> > global_inventory ( 1000, std::vector<short> ( 11 ) );
std::vector<std::string>  global_inventory_name ( 1000 );

void overlord::new_entity(entity* x) {
entity_list.push_back(*x);
}

void overlord::give_entity_item(int x, short ID) {
std::string namex;
namex = global_inventory_name.at(ID);
entity_list.at(x).add_inventory( global_inventory.at(ID).at(0), namex, (short)global_inventory.at(ID).at(1), (short)global_inventory.at(ID).at(2), (short)global_inventory.at(ID).at(3),
(short)global_inventory.at(ID).at(4), (short)global_inventory.at(ID).at(5), (short)global_inventory.at(ID).at(6), global_inventory.at(ID).at(7), global_inventory.at(ID).at(8),
global_inventory.at(ID).at(9), global_inventory.at(ID).at(10)
);
}


//id, location, equipt, cosectattk, chance2hit, karma, alive, health, defesne, attack, value
void overlord::new_item(short ID, const std::string namex, const unsigned short locationx, bool equipt, const unsigned char consecutivex,
   const unsigned char chance2hitx, const float karmax, const bool brokenx, const short healthx, const short defensex, const short attackx,
   const short valuex) {

global_inventory_name.at(ID) = namex;

global_inventory.at(ID).at(0)  = ID;
global_inventory.at(ID).at(1)  = locationx;
global_inventory.at(ID).at(2)  = (short)equipt;
global_inventory.at(ID).at(3)  = (short)consecutivex;
global_inventory.at(ID).at(4)  = (short)chance2hitx;
global_inventory.at(ID).at(5)  = (short)karmax;
global_inventory.at(ID).at(6)  = (short)brokenx;
global_inventory.at(ID).at(7)  = healthx;
global_inventory.at(ID).at(8)  = defensex;
global_inventory.at(ID).at(9)  = attackx;
global_inventory.at(ID).at(10) = valuex;

}


 std::string overlord::return_item_name(const short ID, options x) {
   if (x == name) {
      return global_inventory_name.at(ID);
   }
   else return global_inventory_name.at(ID);
 }

 short overlord::return_item_value(const short ID, options x) {
  switch(x) {
    case (location):
    return global_inventory.at(ID).at(1);
    break;
    case (equipt):
    return global_inventory.at(ID).at(2);
    break;
    case (consecutive):
    return global_inventory.at(ID).at(3);
    break;
    case (chance2hit):
    return global_inventory.at(ID).at(4);
    break;
    case (karma):
    return global_inventory.at(ID).at(5);
    break;
    case (broken):
    return global_inventory.at(ID).at(6);
    break;
    case (health):
    return global_inventory.at(ID).at(7);
    break;
    case (defense):
    return global_inventory.at(ID).at(8);
    break;
    case (attack):
    return global_inventory.at(ID).at(9);
    break;
    case (value):
    return global_inventory.at(ID).at(10);
    break;
    default:
    return -1;
    break;
  };
 }


//void overlord::item_add(const short ID, std::string name, const unsigned char * consecutive, const unsigned char * chance2hit,
// const float karma, const short health, const int defense, const short attack) {
//}


