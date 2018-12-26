//
// Created by oriya on 12/16/18.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}

Expression *BinaryExpression::getLeft() {
    return this->left;
}

Expression *BinaryExpression::getRight() {
    return this->right;
}

