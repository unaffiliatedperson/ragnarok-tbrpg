#ifndef GAME_ENTITIES_H_
   #define GAME_ENTITIES_H_
#include "boost/multi_array.hpp" //for entitiy inventory
#include <iostream>
   class entity {

private: //will use set/get to also check for data constraints
   struct npc {
        char * name;
        unsigned short location;
        unsigned char consecutive;
        unsigned char chance2hit;
        float karma;
        bool alive;
        short health;
        short defense;
        short attack;
        short bronze;
        short silver;
        short gold;
        short platnium;

    }; npc npc_stat;
public:
entity(const char * namex, const unsigned short locationx=0,  const unsigned char consecutivex = 0, const unsigned char chance2hitx = 0,
   const float karmax = 3.333, const bool alivex = true, const short healthx = 100, const short defensex = 50, const short attackx = 50,
   const short goldx = 10);

public:
   bool inventory_add(const short ID, const unsigned char * consecutive, const unsigned char * chance2hit, const float karma, const short health, const int defense, const short attack);
   bool add_gold(), sub_gold();


   ~entity();
protected:
   static const short Height = 6;
   static const short Width = 1000;

public:
    char * rtrn_name();
    unsigned short rtrn_location();
    unsigned char rtrn_consecutive();
    unsigned char rtrn_chance2hit();
    float rtrn_karma();
    bool  rtrn_alive();
    short rtrn_health();
    short rtrn_defense();
    short rtrn_attack();
    short rtrn_currency();

    bool set_name();
    bool set_location();
    bool set_consecutive();
    bool set_chance2hit();
    bool set_karma();
    bool set_alive();
    bool set_health();
    bool set_defense();
    bool set_attack(short);
    bool add_currency(short, short ,short);
    bool update_curreny();
    void add_inventory(short);

private:



   };





#endif
