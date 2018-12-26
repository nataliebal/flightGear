//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_CONDITIONCOMMANDFACTORY_H
#define UNTITLED8_CONDITIONCOMMANDFACTORY_H

#include "CommandFactory.h"

class ConditionCommandFactory: public CommandFactory{
    vector<Expression*> myCommands;
public:
    ConditionCommandFactory(vector<Expression*>);
    Command* create() override;
    virtual int numOfParam();
};
#endif //UNTITLED8_CONDITIONCOMMANDFACTORY_H
