//
// Created by dmytro on 9/17/23.
//
#include <iostream>
#ifndef LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
#define LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H

class my_str{
private:
    size_t capacity_m;
    size_t size_m;
    char* data_m;
public:
    my_str(size_t size, char initial); // Khamula + Kohut
    ~my_str(); // Khamula
    my_str(const char* cstr); // Kohut
    my_str(const std::string& str); // Kohut
    my_str(const my_str& str); // Khamula + Kohut
    my_str& operator=(const my_str& mystr); // Kohut
    void swap(my_str& other) noexcept; // Kohut;
    char& operator[](size_t idx); // Kohut
    const char& operator[](size_t idx) const; // Kohut
    char& at(size_t id_x); // Kohut
    const char& at(size_t id_x) const; // Kohut
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
    size_t size() const noexcept; // Kohut
    size_t capacity() const noexcept; // Kohut
    const char* c_str() const; // Khamula + Kohut
    static constexpr size_t not_found = -1; // used
    size_t find(char c, size_t idx = 0); // Kohut
    size_t find(const std::string& str, size_t idx = 0); // Kohut
    size_t find(const char* cstr, size_t idx = 0); // Kohut
    my_str substr(size_t begin, size_t size); // Kohut
};

std::ostream& operator<<(std::ostream& stream, const my_str& str); // Kohut + Khamula

bool operator==(const my_str& str1, const my_str& str2); // Kohut
bool operator!=(const my_str& str1, const my_str& str2); // Kohut
bool operator<(const my_str& str1, const my_str& str2); // Kohut
bool operator>(const my_str& str1, const my_str& str2); // Kohut
bool operator>=(const my_str& str1, const my_str& str2); // Kohut
bool operator<=(const my_str& str1, const my_str& str2); // Kohut

bool operator==(const my_str& str1, const char* str2); // Kohut
bool operator!=(const my_str& str1, const char* str2); // Kohut
bool operator<(const my_str& str1, const char* str2); // Kohut
bool operator>(const my_str& str1, const char* str2); // Khamula
bool operator<=(const my_str& str1, const char* str2); // Khamula
bool operator>=(const my_str& str1, const char* str2); // Khamula

bool operator==(const char* str1, const my_str& str2); // Khamula
bool operator!=(const char* str1, const my_str& str2); // Khamula
bool operator<(const char* str1, const my_str& str2); // Khamula
bool operator>(const char* str1, const my_str& str2); // Khamula
bool operator>=(const char* str1, const my_str& str2); // Khamula
bool operator<=(const char* str1, const my_str& str2); // Khamula


#endif //LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
