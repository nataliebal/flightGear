//
// Created by oriya on 12/19/18.
//

#include "LoopCommand.h"

LoopCommand::LoopCommand(vector<Expression *> myExpression) {
    this->myExpression = myExpression;
}

double LoopCommand::doCommand() {
    if (this->myExpression.size() < 2) {
        throw "illegal operation!";
    }
    vector<Expression *>::iterator it;
    it = this->myExpression.begin();
    Expression *condition = *it;
    it++;
    while (condition->calculate()) {
        for (it; it != this->myExpression.end(); ++it) {
            (*it)->calculate();
        }
    }
    return 0;
}
