#include <iostream>
#include <cstring>
#include "mystr.h"

// Destructor
my_str::~my_str() {
    // Done: Khamula;
    delete[] data_m;
}

// Constructor
my_str::my_str(size_t size, char initial): size_m(size) {
    // Done: Kohut + Khamula;
    capacity_m = size - (size % 16) + 16;

    data_m = new char[capacity_m + 1];
    memset(data_m, initial, size_m);

    data_m[size_m] = '\0';
    }

    // Copying
my_str::my_str(const my_str& cstr){
    // Done: Kohut + Khamula;
    size_m = cstr.size_m;
    capacity_m = size_m - (size_m % 16) + 16;
    data_m = new char[capacity_m + 1];

    memcpy(data_m, cstr.data_m, size_m + 1);
}

//[] operator
char& my_str::operator[](size_t idx){
    // Done: Kohut;
    return data_m[idx];
}

//const [] operator
const char& my_str::operator[](size_t idx) const {
    // Done: Kohut;
    return data_m[idx];
}

// at()
char& my_str::at(size_t idx) {
    if (idx >= size_m) {
        throw std::out_of_range{
            "Index out of range."
        };
    } else {
        return data_m[idx];
    }
}

// const at()
const char& my_str::at(size_t idx) const {
    if (idx >= size_m) {
        throw std::out_of_range{
                "Index out of range."
        };
    } else {
        return data_m[idx];
    }
}