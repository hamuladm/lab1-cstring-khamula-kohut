//
// Created by zahar_kohut on 19.09.23.
//
#include "mystr.h"


int main() {
    my_str str {100, 'h'};
    str.at(2) = 'g';

    my_str str2 {str};

    std::cout << str2.size();

    std::cout << str2.capacity();

    return 0;
}