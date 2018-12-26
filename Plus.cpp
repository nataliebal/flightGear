//
// Created by oriya on 12/16/18.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right){}

double Plus::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}