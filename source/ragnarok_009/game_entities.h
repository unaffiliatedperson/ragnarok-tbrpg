#ifndef GAME_ENTITIES_H_
   #define GAME_ENTITIES_H_
#include "boost/multi_array.hpp" //for entitiy inventory
#include <iostream>
class item {
    public:
        item(char*namex, unsigned short locationx, bool equiptx, unsigned char consecutivex=0, unsigned char chance2hitx=0, float karmax=0,
short healthx=0, short defensex=0, short valuex=0);
        char * name;
        unsigned short location;
        bool equipt;
        unsigned char consecutive;
        unsigned char chance2hit;
        float karma;
        short health;
        short defense;
        short value;
};

   class entity {
    short _item_amount; //private
public:

//std::vector<std::vector<short> > entity_inventory ( 10000, std::vector<short> ( 111 ) );
std::vector <item> inventory;
  enum options {location=0, equipt=1, consecutive=2, chance2hit, karma, broken, health, defense, attack, value, name};
bool inventory_display();
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

   bool inventory_add(item*);
   bool add_gold(), sub_gold();

   ~entity();
protected:
   static const short Height = 11;
   static const short Width = 1000;

public:
    void display_invn_test();
    bool inventory_remove(short ID);
    short return_item_value(const short ID, options x);
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
    bool set_health(short);
    bool set_defense();
    bool set_attack(short);
    bool add_currency(short, short ,short);
    bool update_curreny();
    void add_inventory(item*
    );
    std::string inventory_name_return(char*);

private:


   };





#endif
