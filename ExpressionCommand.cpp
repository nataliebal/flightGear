//
// Created by oriya on 12/18/18.
//

#include "ExpressionCommand.h"

double ExpressionCommand::calculate() {
    return this->myCommand->doCommand();
}

ExpressionCommand::ExpressionCommand(Command *command) {
    this->myCommand = command;
}
