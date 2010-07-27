#ifndef GAME_ENTITIES_H_
   #define GAME_ENTITIES_H_
#include "boost/multi_array.hpp" //for entitiy inventory

   class entity {
public:
entity(const char * namex, const unsigned short locationx=0,  const unsigned char * consecutivex = 0, const unsigned char * chance2hitx = 0,
   const float karmax = 3.333, const bool alivex = true, const short healthx = 100, const short defensex = 50, const short attackx = 50,
   const short goldx = 10);

public:
   bool inventory_add(const short ID, const unsigned char * consecutive, const unsigned char * chance2hit, const float karma, const short health, const int defense, const short attack);
   bool add_gold(), sub_gold();


   ~entity();
protected:
   static const short Height = 6;
   static const short Width = 1000;

private: //will use set/get to also check for data constraints
   struct npc {
        char * name;
        unsigned short location;
        unsigned char * consecutive;
        unsigned char * chance2hit;
        float karma;
        bool alive;
        short health;
        short defense;
        short attack;
        short bronze;
        short silver;
        short gold;
        short platnium;

    }; npc * npc_stat;
private:
    std::vector <std::string> invn_name;
    typedef boost::multi_array <int, 2> invn;
    typedef invn::index index;


   };





#endif
