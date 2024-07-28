//
// Created by 24887 on 2024/7/23.
//

#ifndef ARITHMETIC_PARSER_H
#define ARITHMETIC_PARSER_H

#include <string>

class ArithmeticParser {
public:
    // 构造函数
    ArithmeticParser(const std::string& expression);
    // 计算表达式
    double parse();

private:
    // 表达式字符串
    std::string expr;
    // 当前解析位置
    size_t pos;

    // 跳过空白字符
    void skipWhitespace();
    // 解析一个数字
    double parseNumber();
    // 解析括号内的表达式
    double parseParentheses();
    // 解析因子
    double parseFactor();
    // 解析项
    double parseTerm();
    // 解析表达式
    double parseExpression();
};

#endif // ARITHMETIC_PARSER_H
