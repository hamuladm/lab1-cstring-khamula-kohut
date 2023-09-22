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
my_str::my_str(const my_str& cstr): size_m(cstr.size_m) {
    // Done: Kohut + Khamula;
    capacity_m = cstr.capacity_m;
    data_m = new char[capacity_m + 1];

    memcpy(data_m, cstr.data_m, size_m + 1);
}

my_str::my_str(const char* cstr): size_m(strlen(cstr)) {
    // Done: Kohut;
    capacity_m = size_m - (size_m % 16) + 16;
    data_m = new char[capacity_m + 1];

    memcpy(data_m, cstr, size_m + 1);
}

my_str::my_str(const std::string& str): size_m(str.length()) {
    // Done: Kohut;
    capacity_m = size_m - (size_m % 16) + 16;
    data_m = new char[capacity_m + 1];
    memcpy(data_m, str.c_str(), size_m);

    data_m[size_m] = '\0';
}


// Copy assigment
my_str& my_str::operator=(const my_str& mystr) {
    // Done: Kohut;
    delete[] data_m;

    size_m = mystr.size_m;
    capacity_m = mystr.capacity_m;
    data_m = new char[capacity_m + 1];
    memcpy(data_m, mystr.data_m, size_m + 1);

    return *this;
}

//swap()
void my_str::swap(my_str& other) noexcept {
    // Done: Kohut;
    std::swap(data_m, other.data_m);
    std::swap(size_m, other.size_m);
    std::swap(capacity_m, other.capacity_m);
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
const char& my_str::at(size_t idx) const {
    // Done: Kohut;
    if (idx >= size_m) {
        throw std::out_of_range{
                "Index out of range."
        };
    } else {
        return data_m[idx];
    }
}

// size()
size_t my_str::size() const noexcept {
    // Done: Kohut;
    return size_m;
};

// capacity()
size_t my_str::capacity() const noexcept{
    // Done: Kohut;
    return capacity_m;
};

// find() char
size_t my_str::find(char c, size_t idx) {
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
        return my_str::not_found;
    }
}

//find c-string
size_t my_str::find(const char* cstr, size_t idx) {
    // Done: Kohut;
    if (idx > size_m) {
        throw std::out_of_range{
                "Index is out of range."
        };
    } else {
        bool found = false;
        size_t str_length = strlen(cstr);
        if (str_length > size_m) {
            return not_found;
        }
        for (size_t i = idx; i < size_m - str_length + 1; ++i) {
            for (size_t j = 0; j < str_length; ++j) {
                //std::cout << str.at(j) << ' ' << data_m[i+j] << '\n';
                if (cstr[j] == data_m[i + j]) {
                    if (!found) {
                        found = true;
                    }
                } else {
                    found = false;
                }
            }
            if (found) {
                return i;
            }
        }
        return not_found;
    }
}

//find string
size_t my_str::find(const std::string& str, size_t idx) {
    // Done: Kohut;
    if (idx > size_m) {
        throw std::out_of_range{
                "Index is out of range."
        };
    } else {
        bool found = false;
        size_t str_length = str.length();
        if (str_length > size_m) {
            return not_found;
        }
        for (size_t i = idx; i < size_m - str_length + 1; ++i) {
            for (size_t j = 0; j < str_length; ++j) {
                //std::cout << str.at(j) << ' ' << data_m[i+j] << '\n';
                if (str.at(j) == data_m[i + j]) {
                    if (!found) {
                        found = true;
                    }
                } else {
                    found = false;
                }
            }
            if (found) {
                return i;
            }
        }
        return not_found;
    }
}

my_str my_str::substr(size_t begin, size_t size) {
    // Done: Kohut;
    if (begin > size_m) {
        throw std::out_of_range {
            "Index out of range."
        };
    } else {
        char* temp;
        temp = new char[size];
        memcpy(temp, data_m + begin, size);

        my_str new_my_str = temp;

        delete[] temp;

        std::cout << new_my_str.data_m;

        return new_my_str;
    }
}