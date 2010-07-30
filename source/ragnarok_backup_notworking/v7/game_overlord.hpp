#ifndef GAME_OVERLORD_HPP_INCLUDED
 #define GAME_OVERLORD_HPP_INCLUDED
 #include "game_entities.h"
 #include <iostream>

class items{
    public:
    items(const short ID, std::string name = "item", const unsigned char * consecutive = 0, const unsigned char * chance2hit =0,
 const float karma =0 , const short health=0, const int defense=0, const short attack=0);

    private:
    short ID;
    unsigned char * consecutive_hit;
    unsigned char * chance2hit;
    short karma;
    short defense;
    short attack;
    std::string name;
    long value;
};

class overlord {
  public:
   overlord();
   ~overlord();
   std::vector <entity> entity_list;
   void entity_add(entity*); //pushes entity into vector
   void give_item(int x); //gives entity tiem
   void entity_attack(unsigned char, unsigned char); //test function.
   void set_item(items*); //pushes item into vector
};


#endif // GAME_OVERLORD_HPP_INCLUDED
