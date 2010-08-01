 #include "game_entities.h"

 entity::entity(std::string name, unsigned short location, unsigned char * consecutive, unsigned char * chance2hit, float karma, bool alive, short health, short defense, short attack, short gold ) {
  name = npc_stat->name;
  location = npc_stat->location;
  consecutive = npc_stat->consecutive;
  chance2hit = npc_stat->chance2hit;
  karma = npc_stat->karma;
  alive = npc_stat->alive;
  health = npc_stat->health;
  defense = npc_stat->defense;
  attack = npc_stat->attack;
  gold = npc_stat->gold;
  invn Inventory(boost::extents[Height][Width]); //array for inventory of entitiy
 }
