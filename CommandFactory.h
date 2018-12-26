//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_COMMANDFACTORY_H
#define UNTITLED8_COMMANDFACTORY_H

#include <string>
#include <vector>
#include "Command.h"

using namespace std;

class CommandFactory{
public:
    virtual Command* create()=0;
    virtual int numOfParam()=0;
};

#endif //UNTITLED8_COMMANDFACTORY_H
