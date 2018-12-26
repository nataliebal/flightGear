//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_SLEEPCOMMANDFACTORY_H
#define UNTITLED8_SLEEPCOMMANDFACTORY_H

#include "CommandFactory.h"

class SleepCommandFactory: public CommandFactory{
    vector<string> params;
public:
    SleepCommandFactory(vector<string> params);
    Command* create() override;

    int numOfParam() override;
};
#endif //UNTITLED8_SLEEPCOMMANDFACTORY_H
