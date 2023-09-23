//
// Created by dmytro on 9/17/23.
//
#include <iostream>
#ifndef LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
#define LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H

class my_str_t{
private:
    size_t capacity_m;
    size_t size_m;
    char* data_m;
public:
    my_str_t(size_t size, char initial); // Kohut
    ~my_str_t(); // Khamula
    my_str_t(const char* cstr); // Kohut
    my_str_t(const std::string& str); // Kohut
    my_str_t(const my_str_t& str); // Khamula
    my_str_t& operator=(const my_str_t& mystr); // Kohut
    void swap(my_str_t& other) noexcept; // Kohut;
    char& operator[](size_t idx); // Kohut
    const char& operator[](size_t idx) const; // Kohut
    char& at(size_t id_x); // Kohut
    [[nodiscard]] const char& at(size_t id_x) const; // Kohut
    void reserve(size_t new_capacity); // Done: Khamula
    void shrink_to_fit(); // Done: Khamula
    void resize(size_t new_size, char new_char = ' '); // Done: Khamula
    void clear(); // Done: Khamula
    void insert(size_t idx , const my_str_t& str); // Done: Khamula
    void insert(size_t idx, char c); // Done: Khamula
    void insert(size_t idx, const char* cstr); // Done: Khamula
    void append(const my_str_t& str); // Done: Khamula
    void append(char c); // Done: Khamula
    void append(const char* cstr); // Done: Khamula
    void erase(size_t begin, size_t size); // Done: Khamula
    [[nodiscard]] size_t size() const noexcept; // Kohut
    [[nodiscard]] size_t capacity() const noexcept; // Kohut
    [[nodiscard]] const char* c_str() const; // Khamula + Kohut
    static constexpr size_t not_found = -1; // used
    size_t find(char c, size_t idx = 0); // Kohut
    size_t find(const std::string& str, size_t idx = 0); // Kohut
    size_t find(const char* cstr, size_t idx = 0); // Kohut
    my_str_t substr(size_t begin, size_t size); // Kohut
};

std::ostream& operator<<(std::ostream& stream, const my_str_t& str); // Kohut
std::istream& operator>>(std::istream& stream, my_str_t& str); // Kohut
std::istream& readline(std::istream& stream, my_str_t& str); // Kohut

bool operator==(const my_str_t& str1, const my_str_t& str2); // Kohut
bool operator!=(const my_str_t& str1, const my_str_t& str2); // Kohut
bool operator<(const my_str_t& str1, const my_str_t& str2); // Kohut
bool operator>(const my_str_t& str1, const my_str_t& str2); // Kohut
bool operator>=(const my_str_t& str1, const my_str_t& str2); // Kohut
bool operator<=(const my_str_t& str1, const my_str_t& str2); // Kohut

bool operator==(const my_str_t& str1, const char* str2); // Kohut
bool operator!=(const my_str_t& str1, const char* str2); // Kohut
bool operator<(const my_str_t& str1, const char* str2); // Kohut
bool operator>(const my_str_t& str1, const char* str2); // Khamula
bool operator<=(const my_str_t& str1, const char* str2); // Khamula
bool operator>=(const my_str_t& str1, const char* str2); // Khamula

bool operator==(const char* str1, const my_str_t& str2); // Khamula
bool operator!=(const char* str1, const my_str_t& str2); // Khamula
bool operator<(const char* str1, const my_str_t& str2); // Khamula
bool operator>(const char* str1, const my_str_t& str2); // Khamula
bool operator>=(const char* str1, const my_str_t& str2); // Khamula
bool operator<=(const char* str1, const my_str_t& str2); // Khamula


#endif //LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
