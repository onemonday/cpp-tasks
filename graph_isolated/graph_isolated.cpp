#include "iostream"
#include "fstream"

unsigned int countIsolated (bool** matrix, int& nNodes) {
    unsigned int result = 0;
    bool isNodeIsolated;

    for (int i = 0; i < nNodes; i++) {
        isNodeIsolated = true;
        for (int j = 0; j < nNodes; j++) {
            if (i == j) continue;
            if (matrix[i][j] == 1) {
                isNodeIsolated = false;
                break;
            }
        }
        if (isNodeIsolated) result++;
    }

    return result;
}

int main() {
    std::ifstream file (R"(C:\Users\karak\Documents\Code\cpp-tasks\graph_isolated\testfile.txt)");
    if (!file.is_open()) return 999;

    int nNodes;
    file >> nNodes;

    bool** matrix = new bool* [nNodes];
    for (int i = 0; i < nNodes; i++)
        matrix[i] = new bool[nNodes] {};

    for (int i = 0; i < nNodes; i++) {
        for (int j = 0; j < nNodes; j++) {
            file >> matrix[i][j];
        }
    }

    std::cout << "Current graph:" << std::endl;
    for (int i = 0; i < nNodes; i++) {
        for (int j = 0; j < nNodes; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    std::cout << "Answer: " << countIsolated(matrix, nNodes) << std::endl;
}
