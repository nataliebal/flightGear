//
// Created by oriya on 12/20/18.
//

#ifndef UNTITLED8_CONDITIONCOMMAND_H
#define UNTITLED8_CONDITIONCOMMAND_H

#include "Command.h"

class ConditionCommand: public Command{
vector<Expression*> myCommands;
public:
    ConditionCommand(vector<Expression*> myCommands);

    double doCommand() override;
};
#endif //UNTITLED8_CONDITIONCOMMAND_H
