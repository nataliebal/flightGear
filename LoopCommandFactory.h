//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_LOOPCOMMANDFACTORY_H
#define UNTITLED8_LOOPCOMMANDFACTORY_H

#include "CommandFactory.h"

class LoopCommandFactory: public CommandFactory{
    vector<Expression*> commands;
public:
    LoopCommandFactory(vector<Expression*> commands);
    Command* create() override;

    int numOfParam() override;
};
#endif //UNTITLED8_LOOPCOMMANDFACTORY_H
