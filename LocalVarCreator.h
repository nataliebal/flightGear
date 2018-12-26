//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_LOCALVARCREATOR_H
#define UNTITLED8_LOCALVARCREATOR_H

#include "CommandFactory.h"

class LocalVarCreator:public CommandFactory{
    vector<string> params;
public:
    LocalVarCreator(vector<string> params);
    Command* create();

    int numOfParam() override;
};
#endif //UNTITLED8_VARCREATOR_H
