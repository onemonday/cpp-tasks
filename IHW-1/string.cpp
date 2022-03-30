//
// Created by karak on 3/30/2022.
//

#include "string.h"
#include "iostream"
#include "cstring"

str::str() {
    this->length = 0;
    this->string = nullptr;
}

//str::str(unsigned int length, char* word) {
//    this->length = length;
//
//    if (word == nullptr) this->string = new char[length+1];
//    else this->string = word;
//}


str::str(str &str) {
    this->string = new char[str.length];

    for (int i = 0; i <= str.length; i++)
        this->string[i] = str.string[i];
}


//str::~str() {
//    delete this->string;
//}


str str::operator+(str& right) {
    str result;
    result.length = this->length + right.length - 1;
    result.string = new char[result.length];
    //result.string[result.length - 1] = '\0';

    /*for (int i = 0; i < result.length; i++)
        result.string[i] = 34;*/

    for (unsigned int i = 0; i < this->length - 1; i++)
        result.string[i] = this->string[i];

    for (unsigned int i = 0; i < right.length; i++)
        result.string[this->length - 1 + i] = right.string[i];

    result.string[result.length] = '\0';

    std::cout << strlen(result.string) << std::endl;
    return result;
}


str str::substring(unsigned int startSymbol, unsigned int substringLength) {
    str result;
    result.length = substringLength + 1;
    result.string = new char[result.length];
    unsigned int substringPointer = 0;

    for (unsigned int i = startSymbol; i < startSymbol + substringLength; i++) {
        result.string[substringPointer] = this->string[i];
        substringPointer++;
    }
    result.string[substringLength + 1] = '\0';

    return result;
}

void str::setStr() {
    char input[255];
    std::cout << "Enter string" << std::endl;
    std::cin.getline(input, 255);
    length = strlen(input) + 1;

    string = new char[length];
    strcpy(string, input);
}

void str::print() {
    std::cout << this->string << std::endl;
}
