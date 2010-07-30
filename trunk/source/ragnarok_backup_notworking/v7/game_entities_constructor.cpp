#include "game_entities.h"

entity::entity(const char * namex, const unsigned short locationx,  const unsigned char consecutivex, const unsigned char chance2hitx,
   const float karmax, const bool alivex, const short healthx, const short defensex, const short attackx,
   const short goldx) {

npc_stat.name = (char*)namex;
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

}
