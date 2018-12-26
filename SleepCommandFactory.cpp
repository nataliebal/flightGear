//
// Created by oriya on 12/18/18.
//

#include "SleepCommandFactory.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "ShuntingYard.h"

SleepCommandFactory::SleepCommandFactory(vector<string> params){
    this->params=params;
}

Command *SleepCommandFactory::create() {
    if (this->params.size() != 1) { throw "illegal operation!"; }
    SleepCommand *sleep;
    ShuntingYard shunt = ShuntingYard();
    int milli = (int) shunt.createExpression(this->params.at(0))->calculate();
    sleep = new SleepCommand(milli);
    return sleep;
}

int SleepCommandFactory::numOfParam() {
    return 1;
}


