//
// Created by oriya on 12/18/18.
//

#ifndef UNTITLED8_VARCOMMAND_H
#define UNTITLED8_VARCOMMAND_H

#include <string>
#include "Command.h"


class VarCommand: public Command{
protected:
    string name;
    string value;
public:
    VarCommand(string name,string value){
        this->name=name;
        this->value=value;
    }
};
#endif //UNTITLED8_VARCOMMAND_H
