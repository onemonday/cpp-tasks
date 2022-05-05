//
// Created by karak on 4/27/2022.
//
#include <iostream>
#include <fstream>
#include "input.h"
#include <math.h>

using mathFunction = double (*) (double);

double f1 (double x) {
    return (x * x * x) - 3;
}

double f2 (double x) {
    return (x + 1) * (x + 1);
}

double f3 (double x) {
    return pow(M_E, sqrt(x*x + x + 1));
}

// Approximately integral calculation methods

double leftRectangle(mathFunction f, double leftBorder,
                     double rightBorder, double epsilon)
{
    double h = rightBorder - leftBorder;
    double nextS = h * f(leftBorder);
    double prevS = 0;
    double sum = f(leftBorder);

    do {
        prevS = nextS;
        for (double x = leftBorder + h/2; x < rightBorder; x += h)
            sum += f(x);
        h /= 2;
        nextS = sum * h;
    } while (fabs(prevS - nextS) >= epsilon);

    return nextS;
}

double rightRectangle(mathFunction f, double leftBorder,
                     double rightBorder, double epsilon)
{
    double h = rightBorder - leftBorder;
    double nextS = h * f(rightBorder);
    double prevS = 0;
    double sum = f(rightBorder);

    do {
        prevS = nextS;
        for (double x = leftBorder + h/2; x < rightBorder; x += h)
            sum += f(x);
        h /= 2;
        nextS = sum * h;
    } while (fabs(prevS - nextS) >= epsilon);

    return nextS;
}

double simpson (mathFunction f, double leftBorder,
                double rightBorder, double epsilon)
{
    double h = rightBorder - leftBorder;
    double nextS = h * (f(leftBorder) + f(rightBorder)) / 3;
    double prevS = 0;
    double evenSum = f(leftBorder) + f(rightBorder);
    double oddSum = 0;

    do {
        prevS = nextS;
        evenSum += oddSum / 2;
        oddSum = 0;
        for (double x = leftBorder + h/2; x < rightBorder; x += h)
            oddSum += f(x);
        oddSum *= 4;

        h /= 2;
        nextS = h * (oddSum + evenSum) / 3;
    } while (fabs(prevS - nextS) >= epsilon);

    return nextS;
}

double trapezoid(mathFunction f, double leftBorder,
                        double rightBorder, double epsilon)
{
    double h = rightBorder - leftBorder;
    double sum = (f(leftBorder) + f(rightBorder)) / 2;
    double nextS = h * sum;
    double prevS = 0;

    do {
        prevS = nextS;
        for (double x = leftBorder + h/2; x < rightBorder; x += h)
            sum += f(x);
        h /= 2;
        nextS = sum * h;
    } while (fabs(prevS - nextS) >= epsilon);

    return nextS;
}


int main() {
    std::ifstream file (R"(C:\Users\karak\Documents\Code\cpp-tasks\IHW-3\testfile.txt)");
    if (!file.is_open()) return 1;

    while(file) {
        input data;
        data.readFile(file);


        mathFunction function;
        switch (data.getFunctionNumber()) {
            case 1:
                function = f1;
                break;
            case 2:
                function = f2;
                break;
            case 3:
                function = f3;
                break;
            default:
                return 4;
        }

        std::cout << "Integral value: ";
        switch (data.getMethodNumber()) {
            case 1:
                std::cout << leftRectangle(function, data.getBorderLeft(), data.getBorderRight(),
                                           data.getPrecision());
                break;
            case 2:
                std::cout << rightRectangle(function, data.getBorderLeft(), data.getBorderRight(),
                                            data.getPrecision());
                break;
            case 3:
                std::cout << simpson(function, data.getBorderLeft(), data.getBorderRight(),
                                     data.getPrecision());
                break;
            case 4:
                std::cout << trapezoid(function, data.getBorderLeft(), data.getBorderRight(),
                                       data.getPrecision());
                break;
            default:
                return 5;
        }

        std::cout << std::endl;
        char c;
        file.get(c);
    }
};