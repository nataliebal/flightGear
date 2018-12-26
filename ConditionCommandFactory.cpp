//
// Created by oriya on 12/18/18.
//

#include "ConditionCommandFactory.h"
#include "ConditionCommand.h"

Command *ConditionCommandFactory::create() {
    ConditionCommand *cond = new ConditionCommand(this->myCommands);
    return cond;
}

int ConditionCommandFactory::numOfParam() {
    return -1;
}

ConditionCommandFactory::ConditionCommandFactory(vector<Expression *> myCommands) {
    this->myCommands = myCommands;
}
