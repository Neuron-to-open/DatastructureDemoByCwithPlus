//
// Created by 24887 on 2024/7/23.
//

#ifndef ALL_BRACKET_MATCHER_H
#define ALL_BRACKET_MATCHER_H

#include <string>

class BracketMatcher {

public:
    BracketMatcher();

    bool areBracketsBalanced(const std::string& expression);

private :
    class Stack {
    public:
        Stack();
        bool isEmpty() const;
        void push(char value);
        char pop() ;


    private:
        static const int MAX_SIZE = 100;
        char items[MAX_SIZE];
        int top;
    };

    bool isMatchingPair( char left, char right) const ;
};
#endif //ALL_BRACKET_MATCHER_H
