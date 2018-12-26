//
// Created by oriya on 12/18/18.
//


#ifndef UNTITLED8_PRINTCOMMANDFACTORY_H
#define UNTITLED8_PRINTCOMMANDFACTORY_H

#include "CommandFactory.h"

class PrintCommandFactory : public CommandFactory {
    vector<string> params;
public:
    PrintCommandFactory(vector<string> params);

    Command *create() override;

    int numOfParam() override;
};

#endif //UNTITLED8_PRINTCOMMANDFACTORY_H
