//
// Created by oriya on 12/20/18.
//

#ifndef UNTITLED8_ASSIGNCOMMAND_H
#define UNTITLED8_ASSIGNCOMMAND_H

#include "Command.h"

class AssignCommand : public Command {
    string name;
    double value;
public:
    AssignCommand(string name, string value);

    virtual double doCommand();

    string getName();

    double getValue();
};

#endif //UNTITLED8_ASSIGNCOMMAND_H
