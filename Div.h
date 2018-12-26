//
// Created by oriya on 12/16/18.
//

#ifndef UNTITLED8_DIV_H
#define UNTITLED8_DIV_H

#include "BinaryExpression.h"

class Div:public BinaryExpression{
public:
    Div(Expression* expLeft,Expression* expRight);
    double calculate();
};

#endif //UNTITLED8_DIV_H
