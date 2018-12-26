//
// Created by oriya on 12/19/18.
//

#include "Controller.h"

void Controller::interperter() {
    this->dataReader = DataReader();
    int i = 1;
    vector<string>::iterator it;
    for (it = this->script.begin(); it != this->script.end(); ++it) {
        dataReader.lexer(i, (*it));
        i++;
    }
    vector<ExpressionCommand *> myEx = dataReader.parser();
    vector<ExpressionCommand *>::iterator itor;
    for (itor = myEx.begin(); itor != myEx.end(); ++itor) {
        (*itor)->calculate();
    }

}

Controller::Controller(vector<string> &script) {
    this->script = script;
}

Controller::Controller() {
//    data=Data();
}
