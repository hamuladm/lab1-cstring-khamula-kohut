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
char& my_str::operator[](size_t id_x){
    // Done: Kohut;
    return data_m[id_x];
}

// Minimizing capacity
void my_str::shrink_to_fit(){
    size_t new_capacity = size_m ;
    char* new_data = new char[new_capacity];
    memcpy(data_m, new_data, new_capacity + 1);
    capacity_m = new_capacity;
}

// Making bigger capacity
void my_str::reserve(size_t new_capacity){
    if (new_capacity > capacity_m){
        char* new_data = new char[new_capacity + 1];
        memcpy(new_data, data_m, size_m + 1);
        delete[] data_m;
        data_m = new_data;
        std::cout << capacity_m;
        std::cout << "\n";
        capacity_m = new_capacity;
        std::cout << capacity_m;
        std::cout << "\n";
    }
}

// Clearing string
void my_str::clear(){
    size_m = 0;

}
// Resizing string
void my_str::resize(size_t new_size, char new_char){
    if (new_size < size_m){
        size_m = new_size;
        capacity_m = size_m - (size_m % 16) + 16;
    }
    else if (new_size > size_m && new_size < capacity_m){
        size_m = new_size;
        char* new_data = new char[capacity_m + 1];
        memset(new_data, new_char, new_size + 1);
        delete[] data_m;
        data_m = new_data;
        size_m = new_size;
        capacity_m = size_m - (size_m % 16) + 16;
    }
    else if (new_size > capacity_m){
        reserve(new_size);
        char* new_data = new char[new_size + 1];
        delete[] data_m;
        memset(new_data, new_char, new_size + 1);
        data_m = new_data;
        size_m = new_size;
        capacity_m = size_m - (size_m % 16) + 16;
    }
    std::cout << data_m;
}
// Inserting my_str string
void my_str::insert(size_t idx , const my_str& str){
    if (idx > size_m){
        throw std::out_of_range{
            "Index is bigger than size of string"
        };
    }
    else{
        size_m = size_m + str.size_m;
        capacity_m = size_m - (size_m % 16) + 16;
        char* new_data = new char[capacity_m + 1];
        memmove(new_data, data_m, idx);
        memmove(new_data + idx, str.data_m, str.size_m);
        memmove(new_data + idx + str.size_m, data_m + idx, size_m - idx + 1);

        delete[] data_m;
        data_m = new_data;
        std::cout << data_m;
        std::cout << "\n";
    }
}

// Inserting C-string
void my_str::insert(size_t idx, char c){
    size_m = size_m + strlen(&c);
    capacity_m = size_m - (size_m % 16) + 16;
    char* new_data = new char[capacity_m + 1];
    memmove(new_data, data_m, idx);
    memmove(new_data + idx, &c, 1);
    memmove(new_data + idx + 1, data_m + idx, size_m - idx + 1);

    delete[] data_m;
    data_m = new_data;
    std::cout << data_m;
}

// Erasing my_str from begin to size
void my_str::erase(size_t begin, size_t size){
    if (begin > size_m){
        throw std::out_of_range{
                "Index is bigger than size of string"
        };
    }
    else if (size > size_m - begin){
        char* new_data = new char[capacity_m + 1];
        memcpy(new_data, data_m, begin);
        delete[] data_m;
        data_m = new_data;
        size_m = size_m - size;
        capacity_m = capacity_m = size_m - (size_m % 16) + 16;
        std::cout << data_m;
    }
    else{
        char* new_data = new char[capacity_m + 1];
        memmove(new_data, data_m, begin);
        memmove(new_data + begin, data_m + begin + size, size);
        delete[] data_m;
        data_m = new_data;
        size_m = size_m - size;
        capacity_m = capacity_m = size_m - (size_m % 16) + 16;
        std::cout << data_m;
    }
}