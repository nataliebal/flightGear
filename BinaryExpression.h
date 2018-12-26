//
// Created by oriya on 12/16/18.
//

#ifndef UNTITLED8_BINARYEXPRESSION_H
#define UNTITLED8_BINARYEXPRESSION_H


#include "Expression.h"

class BinaryExpression :public Expression {
protected:
    Expression *left;
    Expression *right;
public:
    BinaryExpression(Expression *left, Expression *right);

    virtual Expression *getLeft();

    virtual Expression *getRight();
};

#endif //UNTITLED8_BINARYEXPRESSION_H
