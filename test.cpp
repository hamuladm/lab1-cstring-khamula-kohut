//
// Created by zahar_kohut on 19.09.23.
//
#include "mystr.h"


int main() {
    my_str str {5, 'h'};
    my_str instr {2, 'g'};
//    str.reserve(30);
//    str.insert(2, instr);
//    str.resize(15, 'f');
    str.erase(1 , 77);
    return 0;
}