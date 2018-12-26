//
// Created by oriya on 12/16/18.
//

#ifndef UNTITLED8_NUMBER_H
#define UNTITLED8_NUMBER_H

#include "Expression.h"

class Number :public Expression {
    double value;
public:
    Number(double val);

    virtual double calculate();

    double getValue();

};

#endif //UNTITLED8_NUMBER_H
