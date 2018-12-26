//
// Created by oriya on 12/20/18.
//

#ifndef UNTITLED8_DATA_H
#define UNTITLED8_DATA_H

#include <map>
#include "BindVarCommand.h"
#include "LocalVar.h"
#include "AssignCommand.h"

using namespace std;


class Data {
    map<string, LocalVar> simboleTable;
    map<string, string> mapVarPath;
    BindVarCommand *bind;
    map<string, BindVarCommand *> bindVarVal;
    bool isNewData;
    vector<AssignCommand *>bindVarCommand;
    int count;
public:
    Data();

    map<string, LocalVar> getSimboleTable() const;

    map<string, string> getMapVarPath() const;

    bool getIsNewData() const;

    void setIsNewData(bool is);

    vector<AssignCommand *>getBind();

    void clearBind();

    map<string, BindVarCommand *> getBindVarVal() const;

    void setSimboleTable(const map<string, LocalVar> &simboleTable);

    void setMapVarPath(const map<string, string> &mapVarPath);

    void setBindVarVal(const map<string, BindVarCommand *> &bindVarVal);

    void addToSimboleTable(string, LocalVar);

    void addToVarPath(string, string);

    void addToBindVarVal(string, BindVarCommand);

    double getVar(string);

    string getPath(string);

    double getBindVal(string);

    void setVarSimboleTable(string name, double val);

    void setVarPath(string name, string path);

    void setVarVal(string name, double);

    void setVarInIndex(int i, double val);
};

#endif //UNTITLED8_DATA_H
