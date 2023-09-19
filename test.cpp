//
// Created by zahar_kohut on 19.09.23.
//
#include "mystr.h"


int main() {
    my_str str {3, 'h'};
    str.at(2) = 'g';

    my_str str2 {str};

    std::cout << str.at(2);

    return 0;
}