//
// Created by oriya on 12/19/18.
//

#ifndef UNTITLED8_OPENDATASERVERCOMMAND_H
#define UNTITLED8_OPENDATASERVERCOMMAND_H

#include "Command.h"
#include "Data.h"
#include <pthread.h>

extern Data data;
class OpenDataServerCommand: public Command{
    int port;
    int hrz;
public:
    OpenDataServerCommand(int port,int hrz);
    virtual double doCommand();
    void setInTable(string buffer);
};
void* runServer(void* s);
#endif //UNTITLED8_OPENDATASERVERCOMMAND_H
