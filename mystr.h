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
    my_str(size_t size, char initial);
    ~my_str();
    my_str(const char* cstr);
    my_str(const std::string& str);
    my_str(const my_str& str);
    my_str& operator=(const my_str& mystr);
    void swap(my_str& other) noexcept;
    char& operator[](size_t idx);
    char& at(size_t idx);
    const char& at(size_t idx) const;
    void reserve(size_t new_capacity); // Done: Khamula
    void shrink_to_fit(); // Done: Khamula
    void resize(size_t new_size, char new_char = ' '); // Done: Khamula
    void clear(); // Done: Khamula
    void insert(size_t idx , const my_str& str); // Done: Khamula
    void insert(size_t idx, char c); // Done: Khamula
    void insert(size_t idx, const char* cstr);
    void append(const my_str& str);
    void append(char c);
    void append(const char* cstr);
    void erase(size_t begin, size_t size); // Done: Khamula
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    const char* c_str() const {return data_m;}
    static constexpr size_t not_found = 1;
    size_t find(char c, size_t idx = 0);
    size_t find(const std::string& str, size_t idx = 0);
    size_t find(const char* cstr, size_t idx = 0);
    my_str substr(size_t begin, size_t size);
};

//std::ostream& operator<<(std::ostream& stream, const my_str& str){
//    stream << str.c_str();
//    return stream;
//};

bool operator==(const my_str& str1, const my_str& str2);
bool operator!=(const my_str& str1, const my_str& str2);
bool operator<(const my_str& str1, const my_str& str2);
bool operator>(const my_str& str1, const my_str& str2);
bool operator>=(const my_str& str1, const my_str& str2);
bool operator<=(const my_str& str1, const my_str& str2);

bool operator==(const my_str& str1, const char* str2);
bool operator!=(const my_str& str1, const char* str2);
bool operator<(const my_str& str1, const char* str2);
bool operator>(const my_str& str1, const char* str2);
bool operator<=(const my_str& str1, const char* str2);
bool operator>=(const my_str& str1, const char* str2);

bool operator==(const char* str1, const my_str& str2);
bool operator!=(const char* str1, const my_str& str2);
bool operator<(const char* str1, const my_str& str2);
bool operator>(const char* str1, const my_str& str2);
bool operator>=(const char* str1, const my_str& str2);
bool operator<=(const char* str1, const my_str& str2);


#endif //LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
