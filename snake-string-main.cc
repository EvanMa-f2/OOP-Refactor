#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "CharSquareGrid.h"

int main(void){
    CharSquareGrid s;
    s.set_Grid();
    s.find_head_tail();
    s.print_snake();
    return 0;
}