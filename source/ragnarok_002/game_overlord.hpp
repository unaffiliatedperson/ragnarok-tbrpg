#ifndef GAME_OVERLORD_HPP_INCLUDED
 #define GAME_OVERLORD_HPP_INCLUDED
 #include "game_entities.h"
using namespace std;
class overlord {
  public:
   overlord();
   ~overlord();
   std::vector <entity> entity_list;
   void add_entity(entity*);
};

overlord::overlord() {

}
overlord::~overlord() {

}

void overlord::give_item(entity* x) {
entity_list.push_back(*x);
}


#endif // GAME_OVERLORD_HPP_INCLUDED
