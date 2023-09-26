// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


/**
 *
 * @date 23.09.23
 * @authors Kohut Zahar, Dmytro Khamula
 *
**/

#include <iostream>
#include <cstring>
#include "mystr.h"

// Destructor
my_str_t::~my_str_t() {
    // Done: Khamula;
    delete[] data_m;
}

// Constructor
my_str_t::my_str_t(size_t size, char initial): size_m(size) {
    // Done: Kohut;
    capacity_m = size - (size % 16) + 16;

    data_m = new char[capacity_m + 1];
    memset(data_m, initial, size_m);

    data_m[size_m] = '\0';
}

// Copying from my_str_t object
my_str_t::my_str_t(const my_str_t& cstr): size_m(cstr.size_m) {
    // Done: Khamula;
    capacity_m = cstr.capacity_m;
    data_m = new char[capacity_m + 1];

    memcpy(data_m, cstr.data_m, size_m + 1);
}

// Copying from Cstring
my_str_t::my_str_t(const char* cstr): size_m(strlen(cstr)) {
    // Done: Kohut;
    capacity_m = size_m - (size_m % 16) + 16;
    data_m = new char[capacity_m + 1];

    memcpy(data_m, cstr, size_m + 1);
}

// Copying from built-in string
my_str_t::my_str_t(const std::string& str): size_m(str.length()) {
    // Done: Kohut;
    capacity_m = size_m - (size_m % 16) + 16;
    data_m = new char[capacity_m + 1];
    memcpy(data_m, str.c_str(), size_m);

    data_m[size_m] = '\0';
}


// Copy assigment
my_str_t& my_str_t::operator=(const my_str_t& mystr) {
    // Done: Kohut;
    if (mystr.data_m == data_m) {
        return *this;
    }

    delete[] data_m;

    size_m = mystr.size_m;
    capacity_m = mystr.capacity_m;
    data_m = new char[capacity_m + 1];
    memcpy(data_m, mystr.data_m, size_m + 1);

    return *this;
}

// swap()
void my_str_t::swap(my_str_t& other) noexcept {
    // Done: Kohut;
    std::swap(data_m, other.data_m);
    std::swap(size_m, other.size_m);
    std::swap(capacity_m, other.capacity_m);
}


// [] operator
char& my_str_t::operator[](size_t idx){
    // Done: Kohut;
    return data_m[idx];
}

// const [] operator
const char& my_str_t::operator[](size_t idx) const {
    // Done: Kohut;
    return data_m[idx];
}

// at()
char& my_str_t::at(size_t idx) {
    // Done: Kohut;
    if (idx >= size_m) {
        throw std::out_of_range{
            "Index out of range."
        };
    } else {
        return data_m[idx];
    }
}

// const at()
const char& my_str_t::at(size_t idx) const {
    // Done: Kohut;
    if (idx >= size_m) {
        throw std::out_of_range{
                "Index out of range."
        };
    } else {
        return data_m[idx];
    }
}

// Getter for size_m
size_t my_str_t::size() const noexcept {
    // Done: Kohut;
    return size_m;
}

// Getter for capacity_m
size_t my_str_t::capacity() const noexcept{
    // Done: Kohut;
    return capacity_m;
}

// Finding char
size_t my_str_t::find(char c, size_t idx) {
    // Done: Kohut;
    if (idx > size_m) {
        throw std::out_of_range{
                "Index is out of range."
        };
    } else {
        for (size_t i = idx; i < size_m; ++i) {
            if (data_m[i] == c) {
                return i;
            }
        }
        return my_str_t::not_found;
    }
}

// Getter for data_m
const char* my_str_t::c_str() const {
    // Done: Kohut;
    return data_m;
}

// Finding Cstring
size_t my_str_t::find(const char* cstr, size_t idx) {
    // Done: Kohut;
    if (idx > size_m) {
        throw std::out_of_range{
                "Index is out of range."
        };
    } else {
        size_t counter = 0;
        size_t str_length = strlen(cstr);
        if (str_length > size_m) {
            return not_found;
        }
        for (size_t i = idx; i < size_m - str_length + 1; ++i) {
            for (size_t j = 0; j < str_length; ++j) {
                if (cstr[j] == data_m[i + j]) {
                    counter++;
                } else {
                    counter = 0;
                    break;
                }
            }
            if (counter == str_length) {
                return i;
            }
        }
        return not_found;
    }
}

// Finding built-in string
size_t my_str_t::find(const std::string& str, size_t idx) {
    // Done: Kohut;
    if (idx > size_m) {
        throw std::out_of_range{
                "Index is out of range."
        };
    } else {
        size_t counter = 0;
        size_t str_length = str.length();
        if (str_length > size_m) {
            return not_found;
        }
        for (size_t i = idx; i < size_m - str_length + 1; ++i) {
            for (size_t j = 0; j < str_length; ++j) {
                if (str.at(j) == data_m[i + j]) {
                    counter++;
                } else {
                    counter = 0;
                    break;
                }
            }
            if (counter == str_length) {
                return i;
            }
        }
        return not_found;
    }
}

// Returns my_str_t substring from begin to size + begin
my_str_t my_str_t::substr(size_t begin, size_t size) {
    // Done: Kohut;
    if (begin > size_m) {
        throw std::out_of_range {
            "Index out of range."
        };
    } else {
        char* temp;
        temp = new char[size];
        memcpy(temp, data_m + begin, size);
        my_str_t new_my_str_t = temp;
        delete[] temp;
        return new_my_str_t;
    }
}

// Minimizing capacity
void my_str_t::shrink_to_fit(){
    // Done: Khamula;
    size_t new_capacity = size_m ;
    char* new_data = new char[new_capacity];
    memcpy(data_m, new_data, new_capacity + 1);
    capacity_m = new_capacity;
    delete[] data_m;
    data_m = new_data;
    data_m[size_m] = '\0';
}

// Making bigger capacity
void my_str_t::reserve(size_t new_capacity){
    // Done: Khamula;
    if (new_capacity > capacity_m){
        char* new_data = new char[new_capacity + 1];
        memcpy(new_data, data_m, size_m + 1);
        delete[] data_m;
        data_m = new_data;
        data_m[size_m] = '\0';
        capacity_m = new_capacity;
    }
}

// Clearing string
void my_str_t::clear(){
    // Done: Khamula;
    size_m = 0;

}
// Resizing string
void my_str_t::resize(size_t new_size, char new_char){
    // Done: Khamula;
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
        data_m[size_m] = '\0';
    }
    else if (new_size > capacity_m){
        reserve(new_size);
        char* new_data = new char[new_size + 1];
        delete[] data_m;
        memset(new_data, new_char, new_size + 1);
        data_m = new_data;
        size_m = new_size;
        capacity_m = size_m - (size_m % 16) + 16;
        data_m[size_m] = '\0';
    }
}

// Inserting my_str_t string
void my_str_t::insert(size_t idx , const my_str_t& str){
    // Done: Khamula;
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
        data_m[size_m] = '\0';
    }
}

// Inserting char
void my_str_t::insert(size_t idx, char c){
    // Done: Khamula;
    if (idx > size_m){
        throw std::out_of_range{
                "Index is bigger than size of string"
        };
    }
    else {
        size_m = size_m + 1;
        capacity_m = size_m - (size_m % 16) + 16;
        char *new_data = new char[capacity_m + 1];
        memmove(new_data, data_m, idx);
        memmove(new_data + idx, &c, 1);
        memmove(new_data + idx + 1, data_m + idx, size_m - idx + 1);

        delete[] data_m;
        data_m = new_data;
        data_m[size_m] = '\0';
    }
}

// Inserting C++ string
void my_str_t::insert(size_t idx, const char* cstr){
    // Done: Khamula;
    if (idx > size_m){
        throw std::out_of_range{
                "Index is bigger than size of string"
        };
    }
    else{
        size_m = size_m + strlen(cstr);
        capacity_m = size_m - (size_m % 16) + 16;
        char* new_data = new char[capacity_m + 1];
        memmove(new_data, data_m, idx);
        memmove(new_data + idx, cstr, strlen(cstr) + 1);
        memmove(new_data + idx + strlen(cstr), data_m + idx, size_m - idx + 1);

        delete[] data_m;
        data_m = new_data;
        data_m[size_m] = '\0';
    }
}

// Erasing my_str_t from begin to size
void my_str_t::erase(size_t begin, size_t size){
    // Done: Khamula;
    if (begin > size_m){
        throw std::out_of_range{
                "Index is bigger than size of string"
        };
    }
    else if (size > size_m - begin){
        char* new_data = new char[capacity_m + 1];
        memmove(new_data, data_m, begin);
        delete[] data_m;
        data_m = new_data;
        size_m = size_m - size;
        capacity_m = size_m - (size_m % 16) + 16;
        data_m[size_m] = '\0';
    }
    else{
        char* new_data = new char[capacity_m + 1];
        memmove(new_data, data_m, begin);
        memmove(new_data + begin, data_m + begin + size, size);
        delete[] data_m;
        data_m = new_data;
        size_m = size_m - size;
        capacity_m = size_m - (size_m % 16) + 16;
        data_m[size_m] = '\0';
    }
}

// Appending my_str_t string
void my_str_t::append(const my_str_t& str){
    // Done: Khamula;
    size_t old_size = size_m;
    size_m = size_m + str.size_m;
    capacity_m = size_m - (size_m % 16) + 16;
    char* new_data = new char[capacity_m + 1];
    memmove(new_data, data_m, old_size);
    memmove(new_data + old_size, str.data_m, str.size_m);
    size_m = size_m + str.size_m;
    capacity_m = size_m - (size_m % 16) + 16;
    delete[] data_m;
    data_m = new_data;
    data_m[size_m] = '\0';
}

// Appending char
void my_str_t::append(char c){
    // Done: Khamula;
    size_m = size_m + 1;
    capacity_m = size_m - (size_m % 16) + 16;
    char* new_data = new char[capacity_m + 1];
    memcpy(new_data, data_m, size_m - 1);
    new_data[size_m - 1] = c;
    delete[] data_m;
    data_m = new_data;
    data_m[size_m] = '\0';
}

// Appending Cstring
void my_str_t::append(const char* cstr){
    // Done: Khamula;
    size_t old_size = size_m;
    size_m = size_m + strlen(cstr);
    capacity_m = size_m - (size_m % 16) + 16;
    char* new_data = new char[capacity_m + 1];
    memmove(new_data, data_m, old_size);
    memmove(new_data + old_size, cstr, strlen(cstr) + 1);
    delete[] data_m;
    data_m = new_data;
    data_m[size_m] = '\0';
}

bool operator==(const char* str1, const my_str_t& str2){
    // Done: Khamula;
    if (strlen(str1) != str2.size()){
        return false;
    }
    size_t len = strlen(str1) > str2.size() ? strlen(str1): str2.size();
    for (size_t t = 0; t < len; ++t) {
        if (str1[t] != str2.at(t)) {
            return false;
        }
    }
    return true;
}

bool operator!=(const char* str1, const my_str_t& str2){
    // Done: Khamula;
    return !(str1 == str2);
}

bool operator<(const char* str1, const my_str_t& str2) {
    // Done: Khamula;
    size_t len = strlen(str1) < str2.size() ? strlen(str1) : str2.size();
    for (size_t t = 0; t < len; ++t) {
        if (str1[t] > str2.at(t)) {
            return false;
        }
    }
    if (strlen(str1) < str2.size()) {
        return true;
    }
    return false;
}

bool operator>(const char* str1, const my_str_t& str2){
    // Done: Khamula;
    return ((str1 != str2) && !(str1 < str2));
}

bool operator>=(const char* str1, const my_str_t& str2){
    // Done: Khamula;
    return ((str1 > str2) || (str1 == str2));
}

bool operator<=(const char* str1, const my_str_t& str2){
    // Done: Khamula;
    return ((str1 < str2) || (str1 == str2));
}

bool operator==(const my_str_t& str1, const my_str_t& str2) {
    // Done: Kohut;
    if (str1.size() != str2.size()) {
        return false;
    } else {
        for (size_t i = 0; i < str1.size(); ++i) {
            if (str1[i] == str2[i]) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const my_str_t& str1, const my_str_t& str2) {
    // Done: Kohut;
    return !(str1 == str2);
}

bool operator<(const my_str_t& str1, const my_str_t& str2) {
    // Done: Kohut;
    size_t str1_length = str1.size();
    size_t str2_length = str2.size();

    size_t loop_length = (str1_length < str2_length) ? str1_length : str2_length;

    for (size_t i = 0; i < loop_length; ++i) {
        if (str1[i] < str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        } else {
            continue;
        }
    }

    if ((str1_length == str2_length) || (str1_length > str2_length)) {
        return false;
    } else {
        return true;
    }
}

bool operator>(const my_str_t& str1, const my_str_t& str2) {
    // Done: Kohut;
    return (!(str1 < str2) && (str1 != str2));
}

bool operator<=(const my_str_t& str1, const my_str_t& str2) {
    // Done: Kohut;
    return !(str1>str2);
}

bool operator>=(const my_str_t& str1, const my_str_t& str2) {
    // Done: Kohut;
    return !(str1<str2);
}

bool operator==(const my_str_t& str1, const char* str2) {
    // Done: Kohut;
    size_t str_length = strlen(str2);
    if (str1.size() != str_length) {
        return false;
    } else {
        for (size_t i = 0; i < str1.size(); ++i) {
            if (str1[i] == str2[i]) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const my_str_t& str1, const char* str2) {
    // Done: Kohut;
    return !(str1 == str2);
}

bool operator<(const my_str_t& str1, const char* str2) {
    // Done: Kohut;
    size_t str1_length = str1.size();
    size_t str2_length = strlen(str2);

    size_t loop_length = (str1_length < str2_length) ? str1_length : str2_length;

    for (size_t i = 0; i < loop_length; ++i) {
        if (str1[i] < str2[i]) {
            return true;
        } else if (str1[i] > str2[i]) {
            return false;
        } else {
            continue;
        }
    }

    if ((str1_length == str2_length) || (str1_length > str2_length)) {
        return false;
    } else {
        return true;
    }
}

bool operator>(const my_str_t& str1, const char* str2) {
    // Done: Khamula;
    return (!(str1 < str2) && (str1 != str2));
}

bool operator<=(const my_str_t& str1, const char* str2) {
    // Done: Khamula;
    return !(str1>str2);
}

bool operator>=(const my_str_t& str1, const char* str2) {
    // Done: Khamula;
    return !(str1<str2);
}

std::ostream& operator<<(std::ostream& stream, const my_str_t& str){
    // Done: Kohut;
    stream << str.c_str();
    return stream;
}

std::istream& operator>>(std::istream& stream, my_str_t& str) {
    char temp_c[512];
    stream >> temp_c;
    my_str_t temp = temp_c;
    str.swap(temp);

    return stream;
}

std::istream& readline(std::istream& stream, my_str_t& str) {
    char temp_c[512];
    stream.getline(temp_c, sizeof(temp_c));
    my_str_t temp = temp_c;
    str.swap(temp);

    return stream;
}