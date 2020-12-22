/*
Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation).
Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest),
brackets ( ). Operands: only letters: a,b,...,z. Assume that there is only one
RPN form (no expressions like a*b*c).
Link: https://www.spoj.com/problems/ONP/
*/
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <ctype.h>
#include <sstream>
using namespace std;

map<char, int> precedence;
char operands[] = {'+', '-', '*', '/', '^'};
vector<char> stack;
/*
 * Using the shunting Algorithm
 * a) Print an operand whenever it's read
 * b) Push operator on stack if the stack is empty
 * c) If stack is not empty and top is > in precedence pop until not true
 * d) Once done processing pop any remaining tokens in stack
 * e)
 */

void setUpPrecedence() {
    for(int i = 0; i < 5; i++)
        precedence.insert(pair<char, int>(operands[i], i));
}

bool isOperator(char const &c) {
    if(isalpha(c)) return true;
    else return false;
}

bool isOperand(char const &c) {
    for(int i = 0; i < 5; i++) {
        if(operands[i] == c) return true;
    }
    return false;
}

bool isParentheses(char const &c) {
    if(c == '(' || c == ')') return true;
    return false;
}

void processOperand(char const &c) {
    if(stack.empty()) {
        stack.push_back(c);
        return;
    }
    map<char, int>::iterator newChar;
    map<char, int>::iterator oldChar;
    char top = stack.back();
    newChar = precedence.find(c);
    oldChar = precedence.find(top);

    if(top == '(') {
        stack.push_back(c);
        return;
    }

    if(oldChar->second > newChar->second) {
        while(oldChar->second > newChar->second && !stack.empty()) {
            cout << oldChar->second;
            stack.pop_back();
            if(!stack.empty())
                oldChar = precedence.find(stack.back());
        }
    } else {
        stack.push_back(c);
    }

}

void processParentheses(char const &c) {
    if(c == '(') {
        stack.push_back(c);
        return;
    }

    char top = stack.back();
    bool closingFound = false;
    while(top != '(' && !stack.empty()) {
        cout << top;
        stack.pop_back();
        if(!stack.empty())
            top = stack.back();
        if(top == '(') {
            closingFound = true;
            stack.pop_back();
        }
    }
    if(!closingFound) {
        cout << "\nDidn't find closing parantheses" << endl;
        //exit(-1);
    }
}

int main(void) {
    setUpPrecedence();

    string testCasesStr;
    getline(cin, testCasesStr);

    std::stringstream linestream(testCasesStr);
    int testCases;
    linestream >> testCases;

    for(int i = 0; i < testCases; i++) {
        string expression;
        getline(cin, expression);
        for(char const &token: expression) {
            if(isOperator(token)){
                cout << token;
            } else if (isOperand(token)) {
                processOperand(token);
            } else if (isParentheses(token)){
                processParentheses(token);
            }else {
                cout << "Invalide Token" << '\t' << token << endl;
            }
        }
        cout << endl;
    }

}
