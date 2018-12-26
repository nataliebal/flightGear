//
// Created by oriya on 12/19/18.
//

#ifndef UNTITLED8_LOOPCOMMAND_H
#define UNTITLED8_LOOPCOMMAND_H

#include "Command.h"

class LoopCommand : public Command {
    vector<Expression*> myExpression;
public:
    LoopCommand(vector<Expression*> myExpression);
    virtual double doCommand();
};

#endif //UNTITLED8_LOOPCOMMAND_H
