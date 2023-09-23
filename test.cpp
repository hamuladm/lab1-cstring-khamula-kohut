//
// Created by zahar_kohut on 19.09.23.
//
#include "mystr.h"
#include <string>


int main() {
    my_str a {6, 'h'};
    a = a;
    std::cout << a;
}