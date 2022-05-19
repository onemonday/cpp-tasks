//
// Created by karak on 5/18/2022.
//

#include <iostream>
#include <fstream>
#include "stack.h"
#include "graph.h"

int main() {
    std::ifstream file (R"(C:\Users\karak\Documents\Code\cpp-tasks\IHW-4\testfile.txt)");
    if (!file.is_open()) return 990;

    graph graph;
    graph.read(file);
    file.close();

    std::cout << graph.isTree() << std::endl;
}