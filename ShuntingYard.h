//
// Created by oriya on 12/16/18.
//
#ifndef UNTITLED8_SHUNTINGYARD_H
#define UNTITLED8_SHUNTINGYARD_H
#include <map>
#include "Expression.h"
#include "stack"
#include "Number.h"
#include "Mult.h"
#include "Div.h"
#include "Minus.h"
#include "Plus.h"


using namespace std;



class ShuntingYard {
    map<char, int> prcedence;
public:

    ShuntingYard();

    string checkMinus(string str);

    bool isOperator(char ope);

    void initializeMap();

    int precedence(char operation);

    Expression *createExpression(string tokens);

    Expression *applyOp(Expression *val1, Expression *val2, char operation);
};

#endif //UNTITLED8_SHUNTINGYARD_H
