#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "CharSquareGrid.h"

int main(void){
    CharGrid s;
    set_Grid(s);
    find_head_tail(s);
    print_snake(s);
    return 0;
}