//
// Created by oriya on 12/16/18.
//

#ifndef UNTITLED8_MINUS_H
#define UNTITLED8_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *left, Expression *right);

    double calculate();
};

#endif //UNTITLED8_MINUS_H
