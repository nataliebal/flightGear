//
// Created by oriya on 12/19/18.
//

#include "SleepCommand.h"

double SleepCommand::doCommand() {
    this_thread::sleep_for(chrono::milliseconds(this->milliSec));
    return 0;
}

SleepCommand::SleepCommand(int millisec) {
    this->milliSec = millisec;
}
