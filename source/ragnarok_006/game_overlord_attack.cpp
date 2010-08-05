#include "game_overlord.hpp"

void overlord::entity_attack(short entity1, short entity2) {
bool _entity = false;
bool _continue = true;
short temp_defense1 = entity_list.at(entity1).rtrn_defense();
short temp_defense2 = entity_list.at(entity2).rtrn_defense();
short temp_attack1 = entity_list.at(entity1).rtrn_attack();
short temp_attack2 = entity_list.at(entity2).rtrn_attack();

while (_continue == true) {
if (entity_list.at(entity2).rtrn_health() <= 0) {
_continue = false;
std::cout << entity_list.at(entity1).rtrn_name() << " killed " << entity_list.at(entity2).rtrn_name() << std::endl;
}else if(entity_list.at(entity1).rtrn_health() <= 0) {
_continue = false;
std::cout << entity_list.at(entity2).rtrn_name() << " killed " << entity_list.at(entity1).rtrn_name() << std::endl;
}else if (_continue != false) {
if (_entity == false) {
 //entity_list.at(entity2).set_health(temp_health2 - temp_defense1
 //std::cout << "ENTITY1" << std::endl;
 _entity = true;
 short health2 = entity_list.at(entity2).rtrn_health();
 health2 -= (temp_attack1 / temp_defense2);
 entity_list.at(entity2).set_health(health2);
}
if (_entity == true) {
 //std::cout << "ENTITY2" << std::endl;
 _entity = false;
 short health1 = entity_list.at(entity1).rtrn_health();
 health1 -= (temp_attack2 / temp_defense1);
 entity_list.at(entity1).set_health(health1);
}
else {

}
}
}
}


