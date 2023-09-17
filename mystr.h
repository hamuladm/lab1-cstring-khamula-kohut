//
// Created by dmytro on 9/17/23.
//

#ifndef LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
#define LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H

class my_str{
private:
    char* data;
    size_t capacity;
    size_t size;

public:
    my_str(size_t size, char initial);
    ~my_str();


};


#endif //LAB1_CSTRING_KHAMULA_KOHUT_MYSTR_H
