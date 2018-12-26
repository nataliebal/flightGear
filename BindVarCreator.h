//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_BINDVARCREATOR_H
#define UNTITLED8_BINDVARCREATOR_H

#include "CommandFactory.h"

class BindVarCreator : public CommandFactory {
    vector<string> params;
public:
    BindVarCreator(vector<string> params);

    Command *create() override;

    virtual int numOfParam();
};

#endif //UNTITLED8_BINDVARCREATOR_H
