#include "game_entities.h"

entity::entity(const char * namex, const unsigned short locationx,  const unsigned char consecutivex, const unsigned char chance2hitx,
   const float karmax, const bool alivex, const short healthx, const short defensex, const short attackx,
   const short goldx) {

npc_stat.name = (char*)namex;
npc_stat.location = (const short)locationx;
npc_stat.alive = true;
npc_stat.consecutive = consecutivex;
npc_stat.chance2hit = chance2hitx;
npc_stat.karma = karmax;
npc_stat.health = healthx;
npc_stat.defense = defensex;
npc_stat.attack = attackx;
npc_stat.bronze = 0;
npc_stat.silver = 0;
npc_stat.gold = 0;
npc_stat.platnium = 0;

std::vector<std::vector<short> > entity_inventory ( 10000, std::vector<short> ( 111 ) );
std::vector<std::string>  entity_inventory_name(10000);
  // std::vector<std::vector<short> > entity_inventory ( 1000, std::vector<short> ( 11 ) );
  // std::vector<std::string>  entity_inventory_name ( 1000 );
}
