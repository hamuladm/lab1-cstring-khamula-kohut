//
// Created by dmytro on 9/17/23.
//
#include <iostream>
#ifndef LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
#define LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H

class my_str{
private:
    /**
     *
     * Attributes that can't be changed, but are essential for creating class:
     * @param capacity_m -> Maximum size of out string
     * @param size_m -> Actual size of our string
     * @param data_m -> String content
     *
     **/
    size_t capacity_m;
    size_t size_m;
    char* data_m;
public:
    /**
     *
     * Here are defined all basic methods that need to be written
     *
     **/
    my_str(size_t size, char initial); // Done: Khamula + Kohut
    ~my_str(); // Done: Khamula
    my_str(const char* cstr); // Done: Kohut
    my_str(const std::string& str); // Done: Kohut
    my_str(const my_str& str); // Done: Khamula + Kohut
    my_str& operator=(const my_str& mystr); // Done: Kohut
    void swap(my_str& other) noexcept; // Done: Kohut;
    char& operator[](size_t idx); // Done: Kohut
    const char& operator[](size_t idx) const; // Done: Kohut
    char& at(size_t id_x); // Done: Kohut
    const char& at(size_t id_x) const; // Done: Kohut
    void reserve(size_t new_capacity); // Done: Khamula
    void shrink_to_fit(); // Done: Khamula
    void resize(size_t new_size, char new_char = ' '); // Done: Khamula
    void clear(); // Done: Khamula
    void insert(size_t idx , const my_str& str); // Done: Khamula
    void insert(size_t idx, char c); // Done: Khamula
    void insert(size_t idx, const char* cstr); // Done: Khamula
    void append(const my_str& str); // Done: Khamula
    void append(char c); // Done: Khamula
    void append(const char* cstr); // Done: Khamula
    void erase(size_t begin, size_t size); // Done: Khamula
    size_t size() const noexcept; // Done: Kohut
    size_t capacity() const noexcept; // Done: Kohut
    const char* c_str() const; // Khamula + Kohut
    static constexpr size_t not_found = -1; // Already given
    size_t find(char c, size_t idx = 0); // Done: Kohut
    size_t find(const std::string& str, size_t idx = 0); // Done: Kohut
    size_t find(const char* cstr, size_t idx = 0); // Done: Kohut
    my_str substr(size_t begin, size_t size); // Done: Kohut
};

std::ostream& operator<<(std::ostream& stream, const my_str& str); // Done: Kohut + Khamula

/**
 *
 * Overloading different operators
 * @param str1 -> can be my_str object or Cstring or char
 * @param str2 -> can be my_str object or Cstring or char
 *
 **/

bool operator==(const my_str& str1, const my_str& str2); // Done: Kohut
bool operator!=(const my_str& str1, const my_str& str2); // Done: Kohut
bool operator<(const my_str& str1, const my_str& str2); // Done: Kohut
bool operator>(const my_str& str1, const my_str& str2); // Done: Kohut
bool operator>=(const my_str& str1, const my_str& str2); // Done: Kohut
bool operator<=(const my_str& str1, const my_str& str2); // Done: Kohut

bool operator==(const my_str& str1, const char* str2); // Done: Kohut
bool operator!=(const my_str& str1, const char* str2); // Done: Kohut
bool operator<(const my_str& str1, const char* str2); // Done: Kohut
bool operator>(const my_str& str1, const char* str2); // Done: Khamula
bool operator<=(const my_str& str1, const char* str2); // Done: Khamula
bool operator>=(const my_str& str1, const char* str2); // Done: Khamula

bool operator==(const char* str1, const my_str& str2); // Done: Khamula
bool operator!=(const char* str1, const my_str& str2); // Done: Khamula
bool operator<(const char* str1, const my_str& str2); // Done: Khamula
bool operator>(const char* str1, const my_str& str2); // Done: Khamula
bool operator>=(const char* str1, const my_str& str2); // Done: Khamula
bool operator<=(const char* str1, const my_str& str2); // Done: Khamula


#endif //LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
