//
// Created by oriya on 12/18/18.
//

#include "BindVarCommand.h"
#include "ShuntingYard.h"
#include "Data.h"


extern Data data;

//TODO
double BindVarCommand::doCommand() {
    return this->value;
}

BindVarCommand::BindVarCommand(string name, string value) : VarCommand(name, value) {
    this->name = name;
    //value=path
    if (data.getBindVarVal().count(value)) {
        this->value = data.getBindVal(value);
    } else {
        //this->value = 0;
        this->value=0;
        data.addToVarPath(name, value);
    }
    data.addToVarPath(name, value);
}

void BindVarCommand::setValue(double val) {
    this->value = val;
}

double BindVarCommand::getValue() const {
    return this->value;
}

string BindVarCommand::getName() const {
    return this->name;
}
