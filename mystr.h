/**
 *
 * @date 23.09.23
 * @authors Kohut Zahar, Dmytro Khamula
 *
**/

#include <iostream>
#ifndef LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
#define LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H

class my_str_t{
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
    my_str_t(size_t size, char initial); // Done: Kohut
    ~my_str_t(); // Done: Khamula
    my_str_t(const char* cstr); // Done: Kohut
    my_str_t(const std::string& str); // Done: Kohut
    my_str_t(const my_str_t& str); // Done: Khamula
    my_str_t& operator=(const my_str_t& mystr); // Done: Kohut
    void swap(my_str_t& other) noexcept; // Kohut;
    char& operator[](size_t idx); // Done: Kohut
    const char& operator[](size_t idx) const; // Done: Kohut
    char& at(size_t id_x); // Done: Kohut
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
    [[nodiscard]] size_t size() const noexcept; // Done: Kohut
    [[nodiscard]] size_t capacity() const noexcept; // Done: Kohut
    [[nodiscard]] const char* c_str() const; // Done: Kohut
    static constexpr size_t not_found = -1; // Already given
    size_t find(char c, size_t idx = 0); // Done: Kohut
    size_t find(const std::string& str, size_t idx = 0); // Done: Kohut
    size_t find(const char* cstr, size_t idx = 0); // Done: Kohut
    my_str_t substr(size_t begin, size_t size); // Done: Kohut
};

/**
 *
 * @arg operator<< -> output
 * @arg operator>> -> input without whitespaces
 * @arg readline -> input with whitespaces
 *
 **/
std::ostream& operator<<(std::ostream& stream, const my_str_t& str); // Done: Kohut
std::istream& operator>>(std::istream& stream, my_str_t& str); // Done: Kohut
std::istream& readline(std::istream& stream, my_str_t& str); // Done: Kohut

/**
 *
 * Overloading different operators
 * @param str1 -> can be my_str object or Cstring or char
 * @param str2 -> can be my_str object or Cstring or char
 *
 **/
bool operator==(const my_str_t& str1, const my_str_t& str2); // Done: Kohut
bool operator!=(const my_str_t& str1, const my_str_t& str2); // Done: Kohut
bool operator<(const my_str_t& str1, const my_str_t& str2); // Done: Kohut
bool operator>(const my_str_t& str1, const my_str_t& str2); // Done: Kohut
bool operator>=(const my_str_t& str1, const my_str_t& str2); // Done: Kohut
bool operator<=(const my_str_t& str1, const my_str_t& str2); // Done: Kohut

bool operator==(const my_str_t& str1, const char* str2); // Done: Kohut
bool operator!=(const my_str_t& str1, const char* str2); // Done: Kohut
bool operator<(const my_str_t& str1, const char* str2); // Done: Kohut
bool operator>(const my_str_t& str1, const char* str2); // Done: Khamula
bool operator<=(const my_str_t& str1, const char* str2); // Done: Khamula
bool operator>=(const my_str_t& str1, const char* str2); // Done: Khamula

bool operator==(const char* str1, const my_str_t& str2); // Done: Khamula
bool operator!=(const char* str1, const my_str_t& str2); // Done: Khamula
bool operator<(const char* str1, const my_str_t& str2); // Done: Khamula
bool operator>(const char* str1, const my_str_t& str2); // Done: Khamula
bool operator>=(const char* str1, const my_str_t& str2); // Done: Khamula
bool operator<=(const char* str1, const my_str_t& str2); // Done: Khamula


#endif //LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
