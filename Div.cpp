//
// Created by oriya on 12/16/18.
//

#include "Div.h"
Div::Div(Expression* left,Expression* right):BinaryExpression(left,right){

}
double Div::calculate() {
    return this->getLeft()->calculate() / this->getRight()->calculate();
}