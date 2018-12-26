//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_ASSIGNCOMMANDFACTORY_H
#define UNTITLED8_ASSIGNCOMMANDFACTORY_H

#include "CommandFactory.h"

class AssignCommandFactory : public CommandFactory {
    vector<string> params;
public:
    AssignCommandFactory(vector<string> params);

    Command *create() override;

    int numOfParam() override;
};

#endif //UNTITLED8_ASSIGNCOMMANDFACTORY_H
