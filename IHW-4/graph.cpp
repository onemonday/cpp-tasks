//
// Created by karak on 5/18/2022.
//

#include <fstream>
#include <iostream>
#include "graph.h"
#include "stack.h"


graph::~graph() {
    delete[] nodeColor;

    for (unsigned int i = 0; i < nEdges; i++)
        delete[] incidentMatrix[i];

    delete[] incidentMatrix;
}

void graph::read(std::ifstream &file) {
    file >> nNodes;
    file >> nEdges;

    incidentMatrix = new bool*[nNodes];
    for (int i = 0; i < nNodes; i++)
        incidentMatrix[i] = new bool[nEdges];

    for (int i = 0; i < nNodes; i++)
        for (int j = 0; j < nEdges; j++) {
            // std::cout << "FILLING IN " << i << j << std::endl;
            file >> incidentMatrix[i][j];
            // std::cout << "FILLED " << incidentMatrix[i][j] << std::endl;
        }
}

void graph::DFS() {
    stack stack;

    nodeColor = new char[nNodes];
    for (int i = 0; i < nNodes; i++)
        nodeColor[i] = 'w';

    stack.push(0);

    while (!stack.isEmpty()) {
        unsigned int currentNodeNumber = stack.peep();
        switch (this->nodeColor[currentNodeNumber]) {
            case 'w':
                this->nodeColor[currentNodeNumber] = 'g';

                for (int j = 0; j < nEdges; j++) {
                    if (incidentMatrix[currentNodeNumber][j] == 1) {
                        for (int i = 0; i < nNodes; i++) {
                            if (i == currentNodeNumber) continue;
                            if (incidentMatrix[i][j] == 1 && nodeColor[i] == 'w') {
                                stack.push(i);
                                break;
                            }
                        }
                    }
                }
                break;
            case 'g':
                nodeColor[currentNodeNumber] = 'b';
                stack.pop();
                break;
            default:
                return;
        }
    }
}

bool graph::isTree() {
    this->DFS();
    for (int i = 0; i < nNodes; i++)
        if (nodeColor[i] != 'b') return false;

    return true;
}
