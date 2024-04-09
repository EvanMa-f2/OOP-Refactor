#ifndef CHARSQUAREGRID_H
#define CHARSQUAREGRID_H
#include "Position.h"
#include <string>
#include <vector>
struct CharGrid{
    vector<string> cell;
    int size;
    Position head;
    Position tail;
};

void set_Grid(CharGrid& s);
int cant_walk(const CharGrid s, const Position pos);
void find_head_tail(CharGrid& s);
void print_snake(const CharGrid &s);
bool in_square_grid(const int r, const int c, const int n);
#endif