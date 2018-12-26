//
// Created by oriya on 12/16/18.
//

#ifndef UNTITLED8_PLUS_H
#define UNTITLED8_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression *left, Expression *right);

    virtual double calculate();
};

#endif //UNTITLED8_PLUS_H
