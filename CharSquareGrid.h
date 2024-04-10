#ifndef CHARSQUAREGRID_H
#define CHARSQUAREGRID_H
#include "Position.h"
#include <string>
#include <vector>
class CharSquareGrid{
    private:
        vector<string> cell;
        vector<vector<bool>> walk;
        int size;
        Position head;
        Position tail;
        bool in(const Position &pos) const;
        int neighbor_cant_walk(const Position &pos) const;
        char getCell(const Position &pos) const;
        bool walked(const Position &pos) const;
        void walk_through(const Position &pos);
    public:
        CharSquareGrid(void);
        void set_Grid(void);
        void find_head_tail(void);
        void print_snake(void);
};


#endif