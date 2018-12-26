//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_LOCALVAR_H
#define UNTITLED8_LOCALVAR_H

#include "VarCommand.h"
#include "string"
#include "ShuntingYard.h"

using namespace std;

class LocalVar : public VarCommand {
    string name;
    double value;
public:
    LocalVar(string name, string value);
    double doCommand();
    void setVal(double val);
};

#endif //UNTITLED8_LOCALVAR_H
