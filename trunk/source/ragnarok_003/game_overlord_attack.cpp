#include "game_overlord.hpp"

void overlord::entity_attack(unsigned char entity1, unsigned char entity2) {
short temp_health = entity_list.at(entity1).rtrn_health();
std::cout << "Health " << temp_health << std::endl;
}
