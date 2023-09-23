//
// Created by zahar_kohut on 19.09.23.
//
#include "mystr.h"
#include <string>


int main() {
    my_str str1 {100, 'b'};
    str1[1] = '\n';
    str1[5] = 'j';
    std::cout << str1;
    return 0;
}