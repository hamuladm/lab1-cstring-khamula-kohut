#include <iostream>
#include "string.h"
#include "mystr.h"

// Destructor
my_str::~my_str() {
    delete[] data;
}

// Constructor
my_str::my_str(size_t size, char initial): size_m(size) {

    char data = new char[size_m + 1];
    memset(data, initial, size + 1);
    capacity = size_m * 2;
    }

    // Copying
my_str::my_str(const my_str& cstr){
    memcpy(cstr, data, size_m + 1);
}

