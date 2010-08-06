#ifndef GAME_OVERLORD_HPP_INCLUDED
 #define GAME_OVERLORD_HPP_INCLUDED
 #include "game_entities.h"
 #include "game_saves.hpp"
 #include <iostream>

class overlord {
  public:

  enum options {location=0, equipt=1, consecutive=2, chance2hit, karma, broken, health, defense, attack, value, name};

  public:;
   overlord();
   ~overlord();
   std::vector <entity> entity_list;
   //working with entites
   void new_entity(entity*); //pushes entity into vector
   void give_entity_item(int x, short ID); //gives entity tiem
   void entity_attack(short, short); //test function.
   bool get_input();
   //working with inventory more specifically
   void new_item(short ID, const std::string namex, const unsigned short locationx, bool equipt=true, const unsigned char consecutivex=0,
   const unsigned char chance2hitx=0, const float karmax=0, const bool brokenx=false, const short healthx=0, const short defensex=0, const short attackx=0,
   const short valuex=0);

   std::string return_item_name(const short, enum options);
   short return_item_value(const short, enum options);
   //private:

};


#endif // GAME_OVERLORD_HPP_INCLUDED
