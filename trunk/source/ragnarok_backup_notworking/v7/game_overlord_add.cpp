#include "game_overlord.hpp"
#include "items.h"

items::items(const short IDx, std::string name, const unsigned char * consecutivex, const unsigned char * chance2hitx,
 const float karmax , const short healthx, const int defensex, const short attackx) {

 }

//will assume it really exists :O
void overlord::entity_add(entity* x) {
entity_list.push_back(*x);
}

void overlord::set_item(items *) {

}
