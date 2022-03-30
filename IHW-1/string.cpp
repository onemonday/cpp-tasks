//
// Created by karak on 3/30/2022.
//

#include "string.h"

str::str(unsigned int length, char* word) {
    this->length = length;

    if (word == nullptr) this->string = new char[length+1];
    else this->string = word;
}


str::str(str &str) {
    for (int i = 0; i <= length; i++)
        this->string[i] = str.string[i];
}


str::~str() {
    delete this->string;
}


str str::operator+(str& right) {
    str result(this->length + right.length);
    for (unsigned int i = 0; i < this->length; i++)
        result.string[i] = this->string[i];

    for (unsigned int i = 0; i <= right.length; i++)
        result.string[this->length + i] = right.string[i];

    result.string[result.length] = '\0';
    return result;
}


str str::substring(unsigned int startSymbol, unsigned int substringLength) {
    str result(substringLength);
    unsigned int substringPointer = 0;

    for (unsigned int i = startSymbol; i < startSymbol + substringLength; i++)
        result.string[substringPointer] = this->string[i];
    result.string[substringLength] = '\0';

    return result;
}
