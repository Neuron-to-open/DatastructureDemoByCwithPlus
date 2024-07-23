//
// Created by 24887 on 2024/7/23.
//

#include "bracket_matcher.h"
#include <iostream>
using namespace std;

BracketMatcher::Stack::Stack() : top(-1) {}

bool BracketMatcher::Stack::isEmpty() const {
    return top == -1;
}

void BracketMatcher::Stack::push(char value) {
    if (top == MAX_SIZE - 1) {
        cout << "Stack overflow" << endl;
        exit(1);
    } else {
        items[++top] = value;
    }
}

char BracketMatcher::Stack::pop() {
    if (isEmpty()) {
        cout << "Stack underflow" << endl;
        exit(1);
    } else {
        return items[top--];
    }
}

BracketMatcher::BracketMatcher() {}


bool BracketMatcher::isMatchingPair(char left, char right) const {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}
bool BracketMatcher::areBracketsBalanced(const string& expression) {
    Stack s ;
    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty() || !isMatchingPair(s.pop(), ch)) {
                return false;
            }
        }
    }

    return s.isEmpty();
}
