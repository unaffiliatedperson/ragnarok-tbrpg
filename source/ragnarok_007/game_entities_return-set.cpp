#include "game_entities.h"

//return types for entities.h
    char * entity::rtrn_name() {return npc_stat.name;}
    unsigned short entity::rtrn_location() {return npc_stat.location;}
    unsigned char entity::rtrn_consecutive() {return npc_stat.consecutive;}
    unsigned char entity::rtrn_chance2hit() {return npc_stat.chance2hit;}
    float entity::rtrn_karma() {return npc_stat.karma;}
    bool  entity::rtrn_alive() {return npc_stat.alive;}
    short entity::rtrn_health() {return npc_stat.health;}
    short entity::rtrn_defense() {return npc_stat.defense;}
    short entity::rtrn_attack() {return npc_stat.attack;}
    bool entity::set_health(short x) {npc_stat.health = x; if (npc_stat.health == x) {return true;} else return false;}

//updates the current currency
bool entity::set_attack(short x) {
 npc_stat.attack =  x;
}
bool entity::update_curreny() {
    short *gold = &npc_stat.gold;
    short *silver = &npc_stat.silver;
    short *bronze = &npc_stat.bronze;
    short *platnium = &npc_stat.platnium;

    while (*bronze > 100) {
     bronze -= 100;
     silver++;
    }
    while (*silver > 100) {
     silver -= 100;
     gold++;
    }
    while (*gold > 100) {
     gold -= 100;
     platnium++;
    }
    if (*platnium >= 1000) {
     *platnium = 9999;
    }
    *platnium = 99999;
    if ((((*gold > 100) || (*silver > 100) || (*bronze > 100) || (*platnium >= 10000)))) {
     return false;
    }
    else return true;

}
bool entity::add_currency(short bronze, short silver, short gold) {
npc_stat.bronze += bronze;
npc_stat.silver += silver;
npc_stat.gold += gold;

//for testing will display here
std::cout <<"b. " <<  npc_stat.bronze << " s. " << npc_stat.silver << " g. " << npc_stat.gold << "p. " << npc_stat.platnium << std::endl;
}
//set types for entities.h

bool entity::set_alive() {
 if (npc_stat.alive == true){
 npc_stat.name =+ " - dead";
 npc_stat.alive = false;
 return true;
 }
 else return false;

}


