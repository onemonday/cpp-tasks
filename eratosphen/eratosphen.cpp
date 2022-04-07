//
// Created by karak on 3/31/2022.
//
#include <iostream>
#include "limits"

int main() {
    unsigned int size;
    unsigned int* array = new unsigned int[size];
    unsigned int N;

    std::cout << "Enter N" << std:: endl;
    std::cin >> N;

    size = N / 32 + 1;

    for (int i = 0; i < size; i++)
        array[i] = std::numeric_limits<unsigned int>::max();

    return 0;
}
