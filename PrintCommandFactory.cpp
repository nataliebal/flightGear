//
// Created by oriya on 12/18/18.
//

#include "PrintCommandFactory.h"
#include "PrintCommand.h"

int PrintCommandFactory::numOfParam() {
    return 1;
}

Command *PrintCommandFactory::create() {
    if (this->params.size() != 1) {
        throw "illegal operation!";
    }
    PrintCommand *print = new PrintCommand(this->params.at(0));
    return print;
}

PrintCommandFactory::PrintCommandFactory(vector<string> params) {
    this->params = params;
}
