//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_OPENDATASERVERCOMMANDFACTORY_H
#define UNTITLED8_OPENDATASERVERCOMMANDFACTORY_H

#include "CommandFactory.h"

class OpenDataServerCommandFactory: public CommandFactory{
    vector<string> params;
public:
     OpenDataServerCommandFactory(vector<string> params);
    virtual Command* create();
    virtual int numOfParam();
};
#endif //UNTITLED8_OPENDATASERVERCOMMANDFACTORY_H
