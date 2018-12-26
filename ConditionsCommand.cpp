//
// Created by natalie on 12/20/18.
//

#include "ConditionsCommand.h"

ConditionsCommand::ConditionsCommand(string conditions) {
    string firstVar;
    unsigned int i = 0;
    for (i; i < conditions.size(); ++i) {
        if (conditions.at(i) == '<' || conditions.at(i) == '>'
            || conditions.at(i) == '=' || conditions.at(i) == '!') {
            break;
        }
        firstVar += conditions.at(i);
    }
    string condition;
    for (i; i < conditions.size(); ++i) {
        if (conditions.at(i) != '<' && conditions.at(i) != '>'
            && conditions.at(i) != '=' && conditions.at(i) != '!') {
            break;
        }
        condition += conditions.at(i);
    }
    string secondVar = conditions.substr(i);
    ShuntingYard firstShun =  ShuntingYard();
    Expression *first = firstShun.createExpression(firstVar);
    this->variable1 = first->calculate();

    ShuntingYard secondShun =  ShuntingYard();
    Expression *second = secondShun.createExpression(secondShun.checkMinus(secondVar));
    this->variable2 = second->calculate();

    this->theConditions = condition;

}

double ConditionsCommand::doCommand() {

    if (this->theConditions == "<=") {
        return ((this->variable1) <= (this->variable2));
    } else if (this->theConditions == ">=") {
        return ((this->variable1) >= (this->variable2));
    } else if (this->theConditions == "==") {
        return ((this->variable1) == (this->variable2));
    } else if (this->theConditions == "!=") {
        return ((this->variable1) != (this->variable2));
    } else if (this->theConditions == "<") {
        return ((this->variable1) < (this->variable2));
    } else if (this->theConditions == ">") {
        return ((this->variable1) > (this->variable2));
    } else {
        throw "NOT AVAILABLE OPERATOR";
    }
}