//
// Created by oriya on 12/18/18.
//

#include "LocalVar.h"
#include "Data.h"

extern Data data;

double LocalVar::doCommand() {
    return this->value;
}

LocalVar::LocalVar(string name, string value) : VarCommand(name, value) {
    ShuntingYard shunt = ShuntingYard();
    Expression *ex = shunt.createExpression(value);
    this->value = ex->calculate();
    this->name = name;
    data.addToSimboleTable(this->name, *this);
}

void LocalVar::setVal(double val) {
    this->value = val;
}
