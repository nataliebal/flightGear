//
// Created by oriya on 12/18/18.
//

#include "Data.h"
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

Data::Data() {
    this->isNewData = false;
    BindVarCommand *bind = new BindVarCommand("0", "0");
    this->bindVarVal = {{"1 /instrumentation/airspeed-indicator/indicated-speed-kt",         bind},
                        {"2 /instrumentation/altimeter/indicated-altitude-ft",               bind},
                        {"3 /instrumentation/altimeter/pressure-alt-ft",                     bind},
                        {"4 /instrumentation/attitude-indicator/indicated-pitch-deg",        bind},
                        {"5 /instrumentation/attitude-indicator/indicated-roll-deg",         bind},
                        {"6 /instrumentation/attitude-indicator/internal-pitch-deg",         bind},
                        {"7 /instrumentation/attitude-indicator/internal-roll-deg",          bind},
                        {"8 /instrumentation/encoder/indicated-altitude-ft",                 bind},
                        {"9 /instrumentation/encoder/pressure-alt-ft",                       bind},
                        {"10 /instrumentation/gps/indicated-altitude-ft",                    bind},
                        {"11 /instrumentation/gps/indicated-ground-speed-kt",                bind},
                        {"12 /instrumentation/gps/indicated-vertical-speed",                 bind},
                        {"13 /instrumentation/heading-indicator/indicated-heading-deg",      bind},
                        {"14 /instrumentation/magnetic-compass/indicated-heading-deg",       bind},
                        {"15 /instrumentation/slip-skid-ball/indicated-slip-skid",           bind},
                        {"16 /instrumentation/turn-indicator/indicated-turn-rate",           bind},
                        {"17 /instrumentation/vertical-speed-indicator/indicated-speed-fpm", bind},
                        {"18 /controls/flight/aileron",                                      bind},
                        {"19 /controls/flight/elevator",                                     bind},
                        {"20 /controls/flight/rudder",                                       bind},
                        {"21 /controls/flight/flaps",                                        bind},
                        {"22 /controls/engines/engine/throttle",                             bind},
                        {"23 /engines/engine/rpm",                                           bind}};;
    this->simboleTable = map<string, LocalVar>();
    this->mapVarPath = map<string, string>();
    this->bindVarCommand = vector<AssignCommand *>();
    this->count = 23;
}

void Data::setSimboleTable(const map<string, LocalVar> &simboleTable) {
    Data::simboleTable = simboleTable;
}

void Data::setMapVarPath(const map<string, string> &mapVarPath) {
    Data::mapVarPath = mapVarPath;
}

void Data::setBindVarVal(const map<string, BindVarCommand *> &bindVarVal) {
    Data::bindVarVal = bindVarVal;
}

map<string, LocalVar> Data::getSimboleTable() const {
    return this->simboleTable;
}

map<string, string> Data::getMapVarPath() const {
    return this->mapVarPath;
}

map<string, BindVarCommand *> Data::getBindVarVal() const {
    return this->bindVarVal;
}

void Data::addToVarPath(string name, string path) {
    this->mapVarPath.insert(pair<string, string>(name, path));
}

void Data::addToSimboleTable(string name, LocalVar value) {
    this->simboleTable.insert(pair<string, LocalVar>(name, value));
}

void Data::addToBindVarVal(string path, BindVarCommand value) {
    this->bindVarVal.insert(pair<string, BindVarCommand *>(path, &value));
}

double Data::getVar(string var) {
    return this->simboleTable.at(var).doCommand();
}

string Data::getPath(string var) {
    return this->mapVarPath.at(var);
}

double Data::getBindVal(string var) {
    map<string, BindVarCommand *>::iterator it;
    string path;
    for (it = this->bindVarVal.begin(); it != this->bindVarVal.end(); ++it) {
        path = it->first.substr(it->first.find("/"));
        if (path == var) {
            return this->bindVarVal.at(it->first)->doCommand();
        }
    }
    return 0;
}

void Data::setVarSimboleTable(string name, double val) {
    if (this->simboleTable.count(name)) {
        this->simboleTable.at(name).setVal(val);
    }
}

void Data::setVarPath(string name, string path) {
    if (this->mapVarPath.count(name)) {
        this->mapVarPath.at(name) = path;
    }
}

void Data::setVarVal(string name, double val) {
    map<string, BindVarCommand *>::iterator it;
    string path;
    for (it = this->bindVarVal.begin(); it != this->bindVarVal.end(); ++it) {
        path = it->first.substr(it->first.find("/"));
        if (path == name) {
            this->bindVarVal.at(it->first)->setValue(val);
            break;
        }
    }
    this->isNewData = true;
    this->bindVarCommand.push_back(new AssignCommand(name, to_string(val)));
}

void Data::setVarInIndex(int i, double val) {
    map<string, BindVarCommand *>::iterator it;
    it = this->bindVarVal.begin();
    for (int k = 0; k < i; k++) {
        it++;
    }
    it->second->setValue(val);
}

bool Data::getIsNewData() const {
    return this->isNewData;
}

void Data::setIsNewData(bool is) {
    this->isNewData = is;
}

vector<AssignCommand *> Data::getBind() {
    return this->bindVarCommand;
}

void Data::clearBind() {
    this->bindVarCommand.clear();
}


