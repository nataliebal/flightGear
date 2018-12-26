//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_CONNECTCOMMANDFACTORY_H
#define UNTITLED8_CONNECTCOMMANDFACTORY_H

#include "CommandFactory.h"

class ConnectCommandFactory : public CommandFactory {
    vector<string> params;
public:
    ConnectCommandFactory(vector<string>);

    Command *create() override;

    virtual int numOfParam();
};

#endif //UNTITLED8_CONNECTCOMMANDFACTORY_H
