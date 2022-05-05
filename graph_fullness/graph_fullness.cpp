//
// Created by karak on 4/28/2022.
//
#include <iostream>
#include <fstream>
#include "sstream"

bool checkFullness(bool** graph, int& nNodes) {
    for (int i = 0; i < nNodes; i++)
        for (int j = i + 1; j < nNodes; j++)
            if (graph[i][j] == false) return false;

    return true;
}

bool** createAddition (bool** graph, int& nNodes) {
    bool** matrix = new bool* [nNodes];
    for (int i = 0; i < nNodes; i++)
        matrix[i] = new bool[nNodes] {};

    for (int i = 0; i < nNodes; i++)
        for (int j = i+1; j < nNodes; j++)
            if (graph[i][j] == 0) {
                matrix[i][j] == 1;
                matrix[j][i] == 1;
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

    int stringNumber = 1;
    char c;
    while (file) {
        file.get(c);
        std::cout << c;
        if (c == ' ' || c == '\n') {
            stringNumber++;
            continue;
        }

        std::stringstream ss;
        int columnNumber;
        ss << c;
        ss >> columnNumber;

        matrix[stringNumber][columnNumber] = true;
    }

    std::cout << "Fullness " << checkFullness(matrix, nNodes) << std::endl;
    bool** addiction = createAddition(matrix, nNodes);
    for (int i = 0; i < nNodes; i++) {
        for (int j = 0; j < nNodes; j++)
            std::cout << addiction[i][j] << " ";
        std::cout << std::endl;
    }
};