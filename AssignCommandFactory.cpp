//
// Created by oriya on 12/18/18.
//

#include "AssignCommandFactory.h"
#include "Command.h"
#include "AssignCommand.h"

int AssignCommandFactory::numOfParam() {
    return 2;
}

Command *AssignCommandFactory::create() {
    if (this->params.size() != 2) { throw "illegal operation!"; }
    AssignCommand *assignCommand = new AssignCommand(this->params.at(0), this->params.at(1));
    return assignCommand;
}

AssignCommandFactory::AssignCommandFactory(vector<string> params) {
    this->params = params;
}
