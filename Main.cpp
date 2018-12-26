//
// Created by oriya on 12/17/18.
//
#include "ShuntingYard.h"
#include "DataReader.h"
#include "OpenDataServerCommand.h"
#include "ConnectCommand.h"
#include "Controller.h"
#include <pthread.h>
#include <vector>
#include <fstream>
#include "iostream"

Data data;

int main(int argc, char *argv[]) {
    vector<string> my_data;
    if (argc != 2) {
        throw "illegal number of params";
    }
    ifstream stream;
    stream.open(argv[1]);
    if (!stream.is_open()) {
        throw "cannot open file!";
    }
    string line;
    while (getline(stream, line)) {
        line=line+'\n';
        my_data.push_back(line);
    }
    stream.close();
    Controller c = Controller(my_data);
    c.interperter();
    return 0;
}
//TODO
//SHUNTING YARD-POINT NUMBERS ^
//TABLES FOR ALL VARS^
//CONNECT
//THREADS
//IF ^
//CONDITION COMMANDS^
//RUN