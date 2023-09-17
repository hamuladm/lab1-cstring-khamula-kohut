#include <iostream>
#include "mystr.h"


my_str::~my_str() {
    delete[] data;
}

my_str::my_str(size_t size, char initial) {
    size_t count = 0;
    char *arr = new char[size + 1];
    for (size_t j = 0; j < size + 1; ++j){
        *(arr + j) = initial;
        count +=1;
    }
    my_str::size = count;
    my_str::data = arr;
    my_str::capacity = my_str::size * 2;

}