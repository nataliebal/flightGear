//
// Created by oriya on 12/19/18.
//

#ifndef UNTITLED8_CONTROLLER_H
#define UNTITLED8_CONTROLLER_H

#include <vector>
#include "string"
#include "map"
#include "DataReader.h"

using namespace std;
extern Data data;

class Controller {
    Controller();
    vector<string> script;
    DataReader dataReader;
public:
    Controller(vector<string> &script);

    void interperter();
};

#endif //UNTITLED8_CONTROLLER_H
