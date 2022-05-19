//
// Created by karak on 5/18/2022.
//

#include "graph.h"


graph::~graph() {
    delete[] nodeColor;

    for (unsigned int i = 0; i < nEdges; i++)
        delete[] incidentMatrix[i];

    delete[] incidentMatrix;
}

void graph::read(std::ifstream file) {
    file >> nNodes;
    file >> nEdges;

    incidentMatrix = new bool*[nNodes];
    for (int i = 0; i < nNodes; i++)
        incidentMatrix[i] = new bool[nEdges];

    for (int i = 0; i < nNodes; i++)
        for (int j = 0; j < nEdges; j++)
            file >> incidentMatrix[i][j];
}

bool graph::isTree() {

}
