//
// Created by oriya on 12/20/18.
//

#include "AssignCommand.h"
#include "ShuntingYard.h"

#include "Data.h"

extern Data data;

AssignCommand::AssignCommand(string name, string value) {
    this->name = name;
    ShuntingYard shuntingYard = ShuntingYard();
    this->value = shuntingYard.createExpression(shuntingYard.checkMinus(value))->calculate();
    if(data.getSimboleTable().count(this->name)) {
        data.setVarSimboleTable(this->name, this->value);
    }else if(data.getMapVarPath().count(this->name)){
        string path=data.getPath(this->name);
        data.setVarVal(path,this->value);
    }
}

double AssignCommand::doCommand() {
    return this->value;
}

double AssignCommand::getValue() {
    return this->value;
}

string AssignCommand::getName() {
    return this->name;
}
