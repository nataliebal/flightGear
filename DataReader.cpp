//
// Created by oriya on 12/17/18.
//

#include "DataReader.h"
#include "ExpressionCommand.h"
#include "BindVarCommand.h"
#include "BindVarCreator.h"
#include "OpenDataServerCommandFactory.h"
#include "PrintCommandFactory.h"
#include "SleepCommandFactory.h"
#include "AssignCommandFactory.h"
#include "LocalVarCreator.h"
#include "ConnectCommandFactory.h"
#include "ConditionsCommand.h"
#include "LoopCommandFactory.h"
#include "ConditionCommandFactory.h"

#define END_OF_LINE '\n'
#define TAB 9

DataReader::DataReader() {
    initializeOpVec();
}

void DataReader::initializeOpVec() {
    this->operations.insert(pair<char, int>('+', 1));
    this->operations.insert(pair<char, int>('-', 1));
    this->operations.insert(pair<char, int>('*', 1));
    this->operations.insert(pair<char, int>('/', 1));
    this->operations.insert(pair<char, int>('=', 1));
    this->operations.insert(pair<char, int>(')', 1));
    this->operations.insert(pair<char, int>('(', 1));
    this->operations.insert(pair<char, int>(',', 1));
    this->operations.insert(pair<char, int>('.', 1));
    this->operations.insert(pair<char, int>('<', 1));
    this->operations.insert(pair<char, int>('>', 1));
    this->operations.insert(pair<char, int>('!', 1));
}

vector<string> DataReader::lexer(int numOfLine, string line) {
    unsigned long index = 0;
    vector<string> demo;
    while (line.at(index) != END_OF_LINE) {
        //if index=" "
        if (line.at(index) == ' ') {
            index++;
            continue;
        }
        //if digit
        if (isdigit(line.at(index))) {
            string val = "";
            // There may be more than one
            // digits in number.
            while (index < line.length() &&
                   isdigit(line[index]) || (line.at(index) == '.')) {
                val += line[index];
                index++;
            }
            index--;
            // string number = to_string(val);
            demo.push_back(val);
            //if one of operations
        } else if (this->operations.count(line.at(index)) || (line.at(index) == '{')
                   || (line.at(index) == '}')) {
            char c = line.at(index);
            string s = "";
            s += c;
            demo.push_back(s);
        }
            //if words
        else if (((line.at(index) >= 'A') && (line.at(index) <= 'Z'))
                 || ((line.at(index) >= 'a') && (line.at(index) <= 'z'))) {
            string val = "";
            // There may be more than one
            // digits in number. 9=tab(ascii)
            while (index < line.length() && (line.at(index) != ' ')
                   && (line.at(index) != TAB) && (line.at(index) != ',') && (line.at(index) != END_OF_LINE)
                   && (line.at(index) != '<') && (line.at(index) != '>') && (line.at(index) != '+') &&
                   (line.at(index) != '-')
                   && (line.at(index) != '/') && (line.at(index) != '*') && (line.at(index) != '=') &&
                   (line.at(index) != ')')
                   && (line.at(index) != '(')) {
                if (index != line.length() - 1 && (line.at(index) == '!') && (line.at(index + 1) == '=')) { break; }
                val += (line[index]);
                index++;
            }
            index--;
            demo.push_back(val);
        }
            //expression in ""
        else if (line.at(index) == '"') {
            string val = "";
            val += '"';
            index++;
            while (index < line.length() && (line.at(index) != '"')) {
                val += (line[index]);
                index++;
            }
            val += "\"";
            demo.push_back(val);
        }
        index++;
    }
    this->commandsList.insert(pair<int, vector<string>>(numOfLine, demo));
    return demo;
}

vector<ExpressionCommand *> DataReader::parser() {
    vector<ExpressionCommand *> myExpressions;
    map<int, vector<string>>::iterator itor;
    for (itor = this->commandsList.begin(); itor != this->commandsList.end(); ++itor) {
        vector<string> v = fromStringToExp(itor->second);
        itor->second = v;
    }
    for (itor = this->commandsList.begin(); itor != this->commandsList.end(); ++itor) {
        ExpressionCommand *ex = executeCommand(itor);
        myExpressions.push_back(ex);
    }
    return myExpressions;
}

vector<string> DataReader::fromStringToExp(vector<string> &commands) {
    vector<string> expressions;
    vector<string>::iterator it;
    for (it = commands.begin(); it != commands.end(); ++it) {
        //if a word
        if (((*it).at(0) == '"') || (((*it).at(0) >= 'a') && ((*it).at(0) <= 'z'))
            || (((*it).at(0) >= 'A') && ((*it).at(0) <= 'Z'))) {
            string var;
            if ((*it).at(0) == '"') {
                var += (*it).substr(1, (*it).size() - 2);
                expressions.push_back(var);
                continue;
                //if the nex one is operator
            }
            while (it!=commands.end()&&((*it) != ",")&&((*it)!="=")) {
                if (((*it).at(0) == '"') || (((*it).at(0) >= 'a') && ((*it).at(0) <= 'z'))
                    || (((*it).at(0) >= 'A') && ((*it).at(0) <= 'Z'))) {
                    if (it + 1 == commands.end()) {
                        var += *it;
                        break;
                    } else if (it != commands.end() && (!this->operations.count((*(it + 1)).at(0)))) {
                        var += *it;
                        break;
                    }
                } else if (((*(it - 1)) == ")") && (!this->operations.count((*it).at(0)))) {
                    it--;
                    break;
                }else if(*it=="{"){break;}
                var += *it;
                if (it != commands.end()) {
                    it++;
                }
            }
            if(it==commands.end()){
                expressions.push_back(var);
                break;
            }
            if(*it=="="){it--;}
            expressions.push_back(var);
        } else if ((*it) == "=") {
            expressions.push_back((*it));
        } else if ((*it) == "{") { continue; }
        else if ((*it) == "}") {
            expressions.push_back(*it);
            continue;
        } else {
            //split to separated expressions
            string var = "";
            //if this is a number and the next one is also a number
            while ((*it) != ",") {
                if (isdigit((*it).at(0))) {
                    if (it + 1 == commands.end()) {
                        var += *it;
                        break;
                    } else if (it != commands.end() && (!this->operations.count((*(it + 1)).at(0)))) {
                        var += *it;
                        break;
                    }
                } else if (((*(it - 1)) == ")") && (!this->operations.count((*it).at(0)))) {
                    it--;
                    break;
                }
                var += *it;
                if (it != commands.end()) {
                    it++;
                }
            }
            if (var != "") {
                expressions.push_back(var);
            }
        }
    }
    return expressions;
}

ExpressionCommand *DataReader::executeCommand(map<int, vector<string>>::iterator &it) {
    ExpressionCommand *ex;
    if (it->second.at(0) == "var") {
        ex = executeVar(it->second);
    } else if (it->second.at(0) == "sleep") {
        ex = executeSleep(it->second);
    } else if (it->second.at(0) == "print") {
        ex = executePrint(it->second);
    } else if ((it->second.at(0) == "while") || (it->second.at(0) == "if")) {
        ConditionsCommand *condition = new ConditionsCommand(it->second.at(1));
        int counter = 1;
        bool isLoop;
        if (it->second.at(0) == "while") { isLoop = true; }
        else if (it->second.at(0) == "if") { isLoop = false; }
        it++;
        vector<Expression *> conditionCommand;
        conditionCommand.push_back(new ExpressionCommand(condition));
        while (counter != 0) {
            if (it->second.at(0) == "}") {
                counter--;
                continue;
            } else if ((it->second.at(0) == "while") || (it->second.at(0) == "if")) { counter++; }
            conditionCommand.push_back(executeCommand(it));
            it++;
        }
        if (isLoop) { ex = executeLoop(conditionCommand); }
        else {
            ex = executeCondition(conditionCommand);
        }
    } else if (it->second.at(0) == "connect") {
        ex = executeConnect(it->second);
    } else if (it->second.at(0) == "openDataServer") {
        ex = executeOpenServer(it->second);
    } else {
        ex = executeAssign(it->second);
    }
    return ex;
}

ExpressionCommand *DataReader::executeVar(vector<string> &expressions) {
    ExpressionCommand *excom;
    vector<string> victor;
    if (expressions.size() < 4) { throw "illegal operation!"; }
    if (expressions.at(3) == "bind") {
        victor = {expressions.at(1), expressions.at(4)};
        excom = new ExpressionCommand(BindVarCreator(victor).create());
    } else {
        victor = {expressions.at(1), expressions.at(3)};
        excom = new ExpressionCommand(LocalVarCreator(victor).create());
    }
    return excom;
}

ExpressionCommand *DataReader::executeAssign(vector<string> &expressions) {
    ExpressionCommand *excom;
    vector<string> victor;
    victor = {expressions.at(0), expressions.at(2)};
    excom = new ExpressionCommand(AssignCommandFactory(victor).create());
    return excom;
}

ExpressionCommand *DataReader::executeSleep(vector<string> &expressions) {
    ExpressionCommand *excom;
    vector<string> victor;
    victor = {expressions.at(1)};
    excom = new ExpressionCommand(SleepCommandFactory(victor).create());
    return excom;
}

ExpressionCommand *DataReader::executePrint(vector<string> &expressions) {
    ExpressionCommand *excom;
    vector<string> victor;
    victor = {expressions.at(1)};
    excom = new ExpressionCommand(PrintCommandFactory(victor).create());
    return excom;
}

ExpressionCommand *DataReader::executeOpenServer(vector<string> &expressions) {
    ExpressionCommand *excom;
    vector<string> victor;
    victor = {expressions.at(1), expressions.at(2)};
    excom = new ExpressionCommand(OpenDataServerCommandFactory(victor).create());
    return excom;
}

ExpressionCommand *DataReader::executeConnect(vector<string> &expressions) {
    ExpressionCommand *excom;
    vector<string> victor;
    victor = {expressions.at(1), expressions.at(2)};
    excom = new ExpressionCommand(ConnectCommandFactory(victor).create());
    return excom;
}

ExpressionCommand *DataReader::executeLoop(vector<Expression *> &ex) {
    ExpressionCommand *excom;
    excom = new ExpressionCommand(LoopCommandFactory(ex).create());
    return excom;
}

ExpressionCommand *DataReader::executeCondition(vector<Expression *> &ex) {
    ExpressionCommand *excom;
    excom = new ExpressionCommand(ConditionCommandFactory(ex).create());
    return excom;
}

void DataReader::setCommandList(map<int, vector<string>> &commandsList) {
    this->commandsList = commandsList;
}
