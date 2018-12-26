//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_EXPRESSIONCOMMAND_H
#define UNTITLED8_EXPRESSIONCOMMAND_H

#include "Expression.h"
#include "Command.h"

class ExpressionCommand: public Expression{
    Command* myCommand;
public:
    ExpressionCommand(Command* command);
    virtual double calculate();
};

#endif //UNTITLED8_EXPRESSIONCOMMAND_H
