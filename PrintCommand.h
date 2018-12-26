//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_PRINTCOMMAND_H
#define UNTITLED8_PRINTCOMMAND_H

#include "Command.h"
#include "string"

using namespace std;

class PrintCommand: public Command{
    string out;
public:
    PrintCommand(string out);
    virtual double doCommand();
};

#endif //UNTITLED8_PRINTCOMMAND_H
