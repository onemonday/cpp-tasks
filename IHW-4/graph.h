//
// Created by karak on 5/18/2022.
//

#ifndef CPP_TASKS_GRAPH_H
#define CPP_TASKS_GRAPH_H

#include <fstream>

class graph {
private:
    unsigned int nNodes;
    unsigned int nEdges;
    bool** incidentMatrix;
    char* nodeColor;
public:
    ~graph();
    void read(std::ifstream &file);
    void DFS();
    bool isTree();
};


#endif //CPP_TASKS_GRAPH_H
