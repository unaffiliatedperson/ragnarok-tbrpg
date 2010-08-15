#include "game_overlord.hpp"
#include "game_int2str.h"
//will assume it really exists :O


std::vector<std::vector<short> > global_inventory ( 1000, std::vector<short> ( 11 ) );
std::vector<std::string>  global_inventory_name ( 1000 );
short plr=0;
bool debug = false;
bool overlord::get_input() {
 std::string usr_input;
 std::cin >> usr_input;

 std::cin.ignore(20, '\n');
 if (usr_input == "exit") {
   return false;
 }
 else if (usr_input == "help") {
  std::cout << "exit | attack | find | debug | inventory (invn) | drop | clear | who" << std::endl;
  return true;

 }
 else if (usr_input == "attack") {
     enum enemies {
      golbin =1
     };
short id;
std::cin.sync();
 std::cin >> id;
 std::cin.ignore(20, '\n');
if ((id != plr) && (id < entity_list.size())) {
  this->entity_attack(plr, id);
}
else {
 std::cout << "Cannot attack that" << std::endl;
}
  return true;
 }
 else if (usr_input == "find") {
       char usr_input[100];
  std::cin.getline(usr_input, 100, '\n');
  if (entity_list.at(plr).inventory_find(usr_input) == -1) {std::cout << "You dont have that item" << std::endl;}
  else {std::cout << "You have that item" << std::endl;}
  return true;
 }
 else if (usr_input == "debug") {
     if (debug == true) {
      std::cout << "debug off" << std::endl;
      debug = false;
     }
     else {
      std::cout << "debug on" << std::endl;
      std::cout << "Entity to emulate: ";
      std::cin >> plr;
      debug = true;
     }
  return true;
 }
 else if ((usr_input == "inventory") || (usr_input == "invn")) {
     if (debug == true) {
  char * namex;
  short id=0;
  std::cout << "entity id: "; std::cin >> id;
  entity_list.at(id).inventory_display();
     }
     else {
      entity_list.at(plr).inventory_display();
     }
  return true;
 }
 else if (usr_input == "drop") {

  char usr_input[100];
  std::cin.getline(usr_input, 100, '\n');
  if (entity_list.at(plr).inventory_find(usr_input) >= 0) {
    if (entity_list.at(plr).inventory_remove(usr_input) == false) {
      std::cout << "You dont have a " << usr_input << std::endl;
      }
      else {std::cout << "You droped a " << usr_input << std::endl;}
  }
  return true;
 }
 else if (usr_input == "global") {
  short ID;
  std::cout << "id? ";
  std::cin >> ID;
  std::cin.ignore(999, '\n');
  entity_list.at(ID).display_invn_test();


  return true;
 }
 else if (usr_input == "clear") {
  unsigned char i;
  for (i=0; i < 100; ++i) {
   std::cout << std::endl;
    }
   return true;
 }
 else if (usr_input == "who") {
     display_entites();
     return true;
 }
 else {std::cout << "garbal gargan?!" << std::endl; return true;}
}

void overlord::display_entites() {
 short i;
 for (i=0; i < entity_ammount; ++i) {
  std::cout << entity_list.at(i).rtrn_name() << " | " << "ID: " << i << std::endl;
 }
}

void overlord::new_entity(entity* x) {
entity_list.push_back(*x);
++entity_ammount;
}

void overlord::new_item(item * x) {
 item_list.push_back(*x);
 ++item_amount;
}
void overlord::give_entity_item(short entity0, short y) {
bool continue_ = entity0 < this->entity_list.size() ? continue_ = true : continue_ = false;  //make sure entity exists
if ((entity_list.at(entity0).inventory.size() < 1000) && (continue_ == true)) {
entity_list.at(entity0).inventory.push_back(item_list.at(y));
}
}

void overlord::trade(short entity1, short entity2, short item_id) { //update for char* not item id
    if (entity_list.at(entity1).inventory_name_return("sword") == "") {
     std::cout << "Error, no item to trade!" << std::endl;
    }
    else {
//     entity_list.at(entity1).inventory_remove(item_id);
    // give_entity_item(0, 0);
    }
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

 void overlord::entity_trade(const char * name/*, short entity1, short entity2*/) {

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


