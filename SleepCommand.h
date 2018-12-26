//
// Created by oriya on 12/19/18.
//

#ifndef UNTITLED8_SLEEPCOMMAND_H
#define UNTITLED8_SLEEPCOMMAND_H

#include "Command.h"
#include <thread>
#include <chrono>
using namespace std;

class SleepCommand : public Command {
    int milliSec;
public:
    SleepCommand(int millisec );
    virtual double doCommand();
};

#endif //UNTITLED8_SLEEPCOMMAND_H
