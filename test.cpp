//
// Created by zahar_kohut on 19.09.23.
//
#include "mystr.h"
#include <cstring>


int main() {
    my_str str {5, 'h'};
    my_str instr {2, 'g'};
    my_str str2 {3, 's'};
    char ch = 'a';
    char ch2 = 'j';
    char* cstr1;
    for (size_t t = 0; t < 4; ++t){
        *(cstr1 + t) = 'k';
    }

    size_t len = 0;
    for (size_t t = 0; t < 4; ++t){
        std::cout << *(cstr1 + 1);
        len += 1;
    }
    std::cout << "\n";
    std::cout << strlen(cstr1);

    std::cout << "\n";
    std::cout << len;
    std::cout << "\n";

    str.reserve(50);
    std::cout << "\n";

    str.insert(2, instr);
    std::cout << "\n";

    str.insert(2, ch);
    std::cout << "\n";

    str.insert(2, cstr1);
    std::cout << "\n";

    str.erase(1 , 6);
    std::cout << "\n";

    str.append(str2);
    std::cout << "\n";

    str.append(ch2);
    std::cout << "\n";

    str.append(cstr1);
    return 0;
}