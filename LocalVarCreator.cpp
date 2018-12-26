//
// Created by oriya on 12/18/18.
//

#include "LocalVarCreator.h"
#include "LocalVar.h"

Command *LocalVarCreator::create() {
    if (params.size() != 2) {
        throw "illegal operation!";
    }
    LocalVar *local = new LocalVar(params.at(0), params.at(1));
    return local;
}

int LocalVarCreator::numOfParam() {
    return 2;
}

LocalVarCreator::LocalVarCreator(vector<string> params) {
    this->params = params;
}
