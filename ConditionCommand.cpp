//
// Created by oriya on 12/20/18.
//

#include "ConditionCommand.h"

double ConditionCommand::doCommand() {
    vector<Expression*>::iterator it;
    if(this->myCommands.size()<2){throw "illegal operation!";}
    if(this->myCommands.at(0)){
       for(it=this->myCommands.begin();it!=this->myCommands.end();++it){
           (*it)->calculate();
       }
    }
    return 0;
}

ConditionCommand::ConditionCommand(vector<Expression *> myCommands) {
    this->myCommands = myCommands;
}
