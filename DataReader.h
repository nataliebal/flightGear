//
// Created by oriya on 12/17/18.
//
#include <vector>
#include "string"
#include "Data.h"
#include "ExpressionCommand.h"
#include <map>

using namespace std;

#ifndef UNTITLED8_DATAREADER_H
#define UNTITLED8_DATAREADER_H

class DataReader {
    vector<string> myCommands;
    map<char, int> operations;
    Data data;
    map<int, vector<string>> commandsList;
public:
    DataReader();

    void setCommandList(map<int, vector<string>> &commandsList);

    void initializeOpVec();

    vector<string> lexer(int numOfLine,string line);

    vector<ExpressionCommand*> parser();

    vector<string> fromStringToExp(vector<string> &commands);

    ExpressionCommand* executeCommand(map<int,vector<string>>::iterator &expressions);

    vector<string> getMyCommands();

    ExpressionCommand* executeVar(vector<string> &ex);

    ExpressionCommand* executeAssign(vector<string> &ex);

    ExpressionCommand* executeSleep(vector<string> &ex);

    ExpressionCommand* executePrint(vector<string> &ex);

    ExpressionCommand* executeOpenServer(vector<string> &ex);

    ExpressionCommand* executeConnect(vector<string> &ex);

    ExpressionCommand* executeLoop(vector<Expression*> &ex);

    ExpressionCommand* executeCondition(vector<Expression*> &ex);
};

#endif //UNTITLED8_DATAREADER_H
