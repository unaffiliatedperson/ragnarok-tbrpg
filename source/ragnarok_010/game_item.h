#ifndef GAME_ITEM_H_INCLUDED
#define GAME_ITEM_H_INCLUDED

class item {
    public:
        item(char *namex, unsigned short locationx, bool equiptx, unsigned char consecutivex=0, unsigned char chance2hitx=0, float karmax=0,
short healthx=0, short defensex=0, short valuex=0);

        const char * name;
        public:
        char * rtrn_name();
        unsigned short location;
        bool equipt;
        unsigned char consecutive;
        unsigned char chance2hit;
        float karma;
        short health;
        short defense;
        short value;
};

#endif // GAME_ITEM_H_INCLUDED
