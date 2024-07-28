//
// Created by 24887 on 2024/7/23.
//

#include "arithmetic_parser.h"
#include <cctype>
#include <cstdlib>
#include <stdexcept>

// 构造函数
ArithmeticParser::ArithmeticParser(const std::string& expression) : expr(expression), pos(0) {}

// 跳过空白字符
void ArithmeticParser::skipWhitespace() {
    while (pos < expr.size() && isspace(expr[pos])) {
        pos++;
    }
}

// 解析一个数字
double ArithmeticParser::parseNumber() {
    skipWhitespace();
    size_t startPos = pos;
    while (pos < expr.size() && (isdigit(expr[pos]) || expr[pos] == '.')) {
        pos++;
    }
    double number = std::stod(expr.substr(startPos, pos - startPos));
    skipWhitespace();
    return number;
}

// 解析括号内的表达式
double ArithmeticParser::parseParentheses() {
    skipWhitespace();
    if (expr[pos] == '(') {
        pos++;
        double result = parseExpression();
        if (expr[pos] == ')') {
            pos++;
        } else {
            throw std::runtime_error("Mismatched parentheses");
        }
        return result;
    } else {
        return parseNumber();
    }
}

// 解析因子
double ArithmeticParser::parseFactor() {
    skipWhitespace();
    if (expr[pos] == '(') {
        return parseParentheses();
    } else {
        return parseNumber();
    }
}

// 解析项
double ArithmeticParser::parseTerm() {
    double result = parseFactor();
    skipWhitespace();
    while (pos < expr.size() && (expr[pos] == '*' || expr[pos] == '/')) {
        char op = expr[pos];
        pos++;
        double right = parseFactor();
        if (op == '*') {
            result *= right;
        } else {
            if (right == 0) {
                throw std::runtime_error("Division by zero");
            }
            result /= right;
        }
        skipWhitespace();
    }
    return result;
}

// 解析表达式
double ArithmeticParser::parseExpression() {
    double result = parseTerm();
    skipWhitespace();
    while (pos < expr.size() && (expr[pos] == '+' || expr[pos] == '-')) {
        char op = expr[pos];
        pos++;
        double right = parseTerm();
        if (op == '+') {
            result += right;
        } else {
            result -= right;
        }
        skipWhitespace();
    }
    return result;
}

// 计算表达式
double ArithmeticParser::parse() {
    return parseExpression();
}
