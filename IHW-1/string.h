//
// Created by karak on 3/30/2022.
//

#ifndef CPP_TASKS_STRING_H
#define CPP_TASKS_STRING_H


class str {
public:
    str();
    // str(unsigned int length = 0, char* word = nullptr);
    str(str& str);
    //~str();

    void setStr();
    void print();
    str operator+ (str& right);
    str substring (unsigned int startSymbol, unsigned int substringLength);
private:
    unsigned int length;
    char * string;
};


#endif //CPP_TASKS_STRING_H
