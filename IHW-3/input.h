//
// Created by karak on 4/27/2022.
//

#ifndef CPP_TASKS_INPUT_H
#define CPP_TASKS_INPUT_H

#include <fstream>

class input {
private:
    double borderLeft;
    double borderRight;
    double precision;
    unsigned int functionNumber;
    unsigned int methodNumber;

public:
    void readFile (std::ifstream &file);

    double getBorderLeft() const;
    double getBorderRight() const;
    double getPrecision() const;
    unsigned int getFunctionNumber() const;
    unsigned int getMethodNumber() const;
};


#endif //CPP_TASKS_INPUT_H
