//
// Created by oriya on 12/18/18.
//

#include "ConnectCommandFactory.h"
#include "ConnectCommand.h"
#include "ShuntingYard.h"

int ConnectCommandFactory::numOfParam() {
    return 2;
}

Command *ConnectCommandFactory::create() {
    if (this->params.size() != 2) { throw "illegal operation!"; }
    ShuntingYard shunt = ShuntingYard();
    int port = (int) shunt.createExpression(shunt.checkMinus(this->params.at(1)))->calculate();
    ConnectCommand *connect = new ConnectCommand(this->params.at(0), port);
    return connect;
}

ConnectCommandFactory::ConnectCommandFactory(vector<string> params) {
    this->params = params;
}
