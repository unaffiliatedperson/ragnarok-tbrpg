#ifndef GAME_OVERLORD_HPP_INCLUDED
 #define GAME_OVERLORD_HPP_INCLUDED
 #include "game_entities.h"
using namespace std;
class overlord {
  public:
   overlord();
   ~overlord();
   std::vector <entity> entity_list;
   void test();
};
overlord::overlord() {

}
overlord::~overlord() {

}
void overlord::test() {
entity * Entity = new entity("Entity0");
entity * Entitys = new entity("Entity0");
}


#endif // GAME_OVERLORD_HPP_INCLUDED
