//
// Created by oriya on 12/18/18.
//

#include "BindVarCreator.h"
#include "BindVarCommand.h"

Command *BindVarCreator::create() {
    if (this->params.size() != 2) {
        throw "illegal operation!";
    }
    BindVarCommand *local = new BindVarCommand(this->params.at(0), this->params.at(1));
    return local;
}

int BindVarCreator::numOfParam() {
    return 0;
}

BindVarCreator::BindVarCreator(vector<string> params) {
    this->params = params;
}
