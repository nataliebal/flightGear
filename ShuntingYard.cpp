//
// Created by oriya on 12/16/18.
//

#include "ShuntingYard.h"
#include "Data.h"

extern Data data;


ShuntingYard::ShuntingYard() {
    initializeMap();
}


void ShuntingYard::initializeMap() {
    this->prcedence.insert(pair<char, int>('/', 2));
    this->prcedence.insert(pair<char, int>('*', 2));
    this->prcedence.insert(pair<char, int>('+', 1));
    this->prcedence.insert(pair<char, int>('-', 1));
    this->prcedence.insert(pair<char, int>(')', 0));
    this->prcedence.insert(pair<char, int>('(', 0));
}

int ShuntingYard::precedence(char operation) {
    if (this->prcedence.count(operation)) {
        return this->prcedence.at(operation);
    }
    throw "invalid operation!";
}

Expression *ShuntingYard::applyOp(Expression *val1, Expression *val2, char operation) {
    switch (operation) {
        case '*':
            return new Mult(val1, val2);
        case '/':
            return new Div(val1, val2);
        case '+':
            return new Plus(val1, val2);
        case '-':
            return new Minus(val1, val2);

        default:
            break;
    }
}

// Function that returns value of
// expression after evaluation.
Expression *ShuntingYard::createExpression(string tokens) {
    int i;

    // stack to store integer values.
    stack<Expression *> values;

    // stack to store operators.
    stack<char> ops;

    for (i = 0; i < tokens.length(); i++) {

        // Current token is a whitespace,
        // skip it.
        if (tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if (isdigit(tokens[i])) {
            string val = "";

            // There may be more than one
            // digits in number.
            while (i < tokens.length() && (isdigit(tokens[i]) || (tokens[i] == '.'))) {
                val += tokens[i];
                i++;
            }
            i--;
            double number = stod(val);
            Expression *num = new Number(number);
            values.push(num);
        }

            // Closing brace encountered, solve
            // entire brace.
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                Expression *val2 = values.top();
                values.pop();

                Expression *val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            ops.pop();
        }

            // Current token is an operator.
        else {
            if (!prcedence.count(tokens[i])) {
                string val = "";
                while ((i < tokens.length()) && (!prcedence.count(tokens[i]))) {
                    val += (tokens[i]);
                    i++;
                }
                i--;
                if (data.getSimboleTable().count(val)) {
                    double number = data.getVar(val);
                    Expression *num = new Number(number);
                    values.push(num);
                } else if (data.getMapVarPath().count(val)) {
                    string path = data.getMapVarPath().at(val);
                    double number = data.getBindVal(path);
                    Expression *num = new Number(number);
                    values.push(num);
                }
                continue;
            }
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while (!ops.empty() && precedence(ops.top())
                                   >= precedence(tokens[i])) {
                Expression *val2 = values.top();
                values.pop();

                Expression *val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);


        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while (!ops.empty()) {
        Expression *val2 = values.top();
        values.pop();

        Expression *val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return values.top();
}

bool ShuntingYard::isOperator(char ope) {
    if (ope == '+' || ope == '-' || ope == '/' || ope == '*') {
        return true;
    } else {
        return false;
    }
}

string ShuntingYard::checkMinus(string str) {
    string newStr;
    int flag = 0;

    for (int i = 0; i < str.length() - 1; i++) {
        if (i == 0 && str[i] == '-') {
            newStr+= "(";
            newStr+= "0";
            newStr+= "-";
            flag = 1;
            continue;
        }
        if (flag && isOperator(str[i])) {
            newStr+=")";
            flag =0;
        }
        switch (str[i]) {
            case 40:
                newStr += "(";
                break;
            case 41:
                newStr += ")";
                break;
            case 42:
                newStr += "*";
                break;
            case 43:
                newStr += "+";
                break;
            case 45:
                newStr += "-";
                break;
            case 46:
                newStr += ".";
                break;
            case 47:
                newStr += "/";
                break;
            case 48:
                newStr += "0";
                break;
            case 49:
                newStr += "1";
                break;
            case 50:
                newStr += "2";
                break;
            case 51:
                newStr += "3";
                break;
            case 52:
                newStr += "4";
                break;
            case 53:
                newStr += "5";
                break;
            case 54:
                newStr += "6";
                break;
            case 55:
                newStr += "7";
                break;
            case 56:
                newStr += "8";
                break;
            case 57:
                newStr += "9";
                break;
        }
        if((isOperator(str[i]) || str[i] == '(') && str[i+1] == '-') {
            newStr += "(";
            newStr += "0";
            newStr += "-";
            flag =1;
            i++;
        }
    }
    newStr += str[str.length()-1];
    if (flag) {
        newStr += ")";
    }
    return newStr;
}

