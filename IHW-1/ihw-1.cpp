//
// Created by karak on 3/29/2022.
//

#include <iostream>
#include "string.h"

int main() {
    setlocale(LC_ALL, "Russian");
    str str1, str2, result, result1;

    std::cout << "Entering string 1" << std::endl;
    str1.setStr();
    std::cout << "Entering string 2" << std::endl;
    str2.setStr();

    result = str1 + str2;
    result.print();

    result1 = str1.substring(1, 3);
    result1.print();

    return 0;
};
