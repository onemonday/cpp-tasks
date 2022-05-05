//
// Created by karak on 4/27/2022.
//

#include "input.h"

void input::readFile(std::ifstream &file) {
    file >> borderLeft;
    file >> borderRight;
    file >> precision;
    file >> functionNumber;
    file >> methodNumber;
}

double input::getBorderLeft() const {
    return borderLeft;
}

double input::getBorderRight() const {
    return borderRight;
}

double input::getPrecision() const {
    return precision;
}

unsigned int input::getFunctionNumber() const {
    return functionNumber;
}

unsigned int input::getMethodNumber() const {
    return methodNumber;
}
