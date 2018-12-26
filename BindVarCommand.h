//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_BINDVARCOMMAND_H
#define UNTITLED8_BINDVARCOMMAND_H

#include "VarCommand.h"

class BindVarCommand : public VarCommand {
    string name;
    double value;
public:
    BindVarCommand(string name, string value);

    virtual double doCommand();

    void setValue(double val);

    string getName() const;

    double getValue() const;
};

#endif //UNTITLED8_BINDVARCOMMAND_H
