//
// Created by zahar_kohut on 19.09.23.
//
#include "mystr.h"
#include <string>


int main() {
    my_str str {10, 'h'};
    str[0] = 'a';
    str[1] = 'b';
    str[2] = 'c';
    str[3] = 'd';
    str[4] = 'e';
    str[5] = 'f';
    str[6] = 'g';
    str[7] = 'h';
    str[8] = 'i';
    str[9] = 'j';


    my_str str2 {5, 'g'};
    str.swap(str2);
    return 0;
}