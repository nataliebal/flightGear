//
// Created by oriya on 12/16/18.
//

#ifndef UNTITLED8_MULT_H
#define UNTITLED8_MULT_H

#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    Mult(Expression *left, Expression *right);

    double calculate();
};

#endif //UNTITLED8_MULT_H
