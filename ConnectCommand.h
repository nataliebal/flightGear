//
// Created by oriya on 12/19/18.
//

#ifndef UNTITLED8_CONNECTCOMMAND_H
#define UNTITLED8_CONNECTCOMMAND_H

#include "Command.h"
#include "Data.h"

extern Data data;

class ConnectCommand : public Command {
    string ip;
    int port;
public:
    ConnectCommand(string ip, int port);

    virtual double doCommand();

    void sendData(string path, double value);
};

#endif //UNTITLED8_CONNECTCOMMAND_H
