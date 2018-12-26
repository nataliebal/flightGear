//
// Created by oriya on 12/18/18.
//

#include "LoopCommandFactory.h"
#include "LoopCommand.h"

Command *LoopCommandFactory::create() {
    LoopCommand* loopCommand=new LoopCommand(this->commands);
    return loopCommand;
}

int LoopCommandFactory::numOfParam() {
    return -1;
}

LoopCommandFactory::LoopCommandFactory(vector<Expression *> commands) {
    this->commands = commands;
}
