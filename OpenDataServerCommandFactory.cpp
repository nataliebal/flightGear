//
// Created by oriya on 12/18/18.
//

#include "OpenDataServerCommandFactory.h"
#include "OpenDataServerCommand.h"
#include "ShuntingYard.h"

OpenDataServerCommandFactory::OpenDataServerCommandFactory(vector<string> params) {
    this->params = params;
}

Command *OpenDataServerCommandFactory::create() {
    if(this->params.size()!=2){throw "illegal operation!";}
    ShuntingYard shunt=ShuntingYard();
    int port=(int)shunt.createExpression(params.at(0))->calculate();
    int hrz=(int)shunt.createExpression(params.at(1))->calculate();
    OpenDataServerCommand* server=new OpenDataServerCommand(port,hrz);
    return server;
}

int OpenDataServerCommandFactory::numOfParam() {
    return 2;
}
