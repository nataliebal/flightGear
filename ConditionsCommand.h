//
// Created by natalie on 12/20/18.
//

#ifndef UNTITLED8_CONDITIONSCOMMAND_H
#define UNTITLED8_CONDITIONSCOMMAND_H

#include "Command.h"
#include "ShuntingYard.h"
#include <pthread.h>

class ConditionsCommand : public Command {
    double variable1;
    double variable2;
    string theConditions;
public:
    ConditionsCommand(string condition);

    virtual double doCommand();
};

void *runClient(void *c);


#endif //UNTITLED8_CONDITIONSCOMMAND_H
