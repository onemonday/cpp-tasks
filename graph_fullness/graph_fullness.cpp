//
// Created by karak on 4/28/2022.
//
#include <iostream>
#include <fstream>
#include "string"
#include "cstring"
#include "sstream"

void toInt (std::string& str, int& number) {
    std::stringstream ss;
    ss << str;
    ss >> number;
}

bool checkFullness(bool** graph, int& nNodes) {
    for (int i = 0; i < nNodes; i++)
        for (int j = i + 1; j < nNodes; j++)
            if (graph[i][j] == false) return false;

    return true;
}

bool** createAddition (bool** graph, int& nNodes) {
    bool** matrix = new bool* [nNodes];
    for (int i = 0; i < nNodes; i++)
        matrix[i] = new bool[nNodes];

    for (int i = 0; i < nNodes; i++)
        for (int j = 0; j < nNodes; j++)
            matrix[i][j] = false;

    for (int i = 0; i < nNodes; i++)
        for (int j = i+1; j < nNodes; j++)
            if (graph[i][j] == false) {
                matrix[i][j] = true;
                matrix[j][i] = true;
            }

    return matrix;
}

int main (){
    std::ifstream file (R"(C:\Users\karak\Documents\Code\cpp-tasks\graph_fullness\testfile.txt)");
    if (!file.is_open()) return 999;

    int nNodes;
    file >> nNodes;
    bool** matrix = new bool* [nNodes];
    for (int i = 0; i < nNodes; i++)
        matrix[i] = new bool[nNodes] {};

    int stringNumber = -1;
    char c;
    std::string currentNumber = "";

    while (file) {
        file.get(c);

        int columnNumber = 0;
        if (c != '\n' && c != ' ') {
            currentNumber += c;
            continue;
        } else {
            //columnNumber = std::stoi(currentNumber);
            if (!currentNumber.empty()) {
                toInt(currentNumber, columnNumber);
                columnNumber--;

                matrix[stringNumber][columnNumber] = true;
                std::cout << currentNumber << " is going to " << stringNumber << " " << columnNumber << std::endl;
            }
            if (c == '\n') stringNumber++;
            currentNumber = "";
            continue;
        }


//
//        std::stringstream ss;
//        int columnNumber;
//        ss << c;
//        ss >> columnNumber;
//        columnNumber--;
    }

    std::cout << "Current graph:" << std::endl;
    for (int i = 0; i < nNodes; i++) {
        for (int j = 0; j < nNodes; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "Fullness " << checkFullness(matrix, nNodes) << std::endl;
    bool** addiction = createAddition(matrix, nNodes);
    for (int i = 0; i < nNodes; i++) {
        for (int j = 0; j < nNodes; j++)
            std::cout << addiction[i][j] << " ";
        std::cout << std::endl;
    }
};