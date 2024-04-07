/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2024-04-07 13:11:33
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-04-07 15:57:48
 * @FilePath: /leetcode/acm/questions/MY0-expr-eval/main.cpp
 * @Description: 表达式求值运算总结
 */

#include <cctype>
#include <cstddef>
#include <functional>
#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
enum Token_type_t
{
    NUM = 0,
    OP,
    L_brackets,
    R_brackets,
};

using num_t = int;
using op_t = enum
{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
};

std::unordered_map<op_t, size_t> oplevel = {
    {ADD, 1},
    {SUB, 1},
    {MUL, 2},
    {DIV, 2},
};

std::unordered_map<op_t, std::function<num_t(num_t, num_t)>> binoperators = {
    {ADD, [](num_t a, num_t b)
     { return a + b; }},
    {SUB, [](num_t a, num_t b)
     { return a - b; }},
    {MUL, [](num_t a, num_t b)
     { return a * b; }},
    {DIV, [](num_t a, num_t b)
     { return a / b; }},
};

struct Token
{
    Token_type_t type;
    union
    {
        num_t num;
        op_t op;
    };
    friend std::ostream &operator<<(std::ostream &os, const Token &obj)
    {
        switch (obj.type)
        {
        case NUM:
            os << obj.num;
            break;
        case OP:
            os << static_cast<char>(obj.op);
            break;
        case L_brackets:
            os << '(';
            break;
        case R_brackets:
            os << ')';
            break;
        }
        return os;
    };
};
std::ostream &operator<<(std::ostream &out, std::vector<Token> o)
{
    if (o.size() == 0)
    {
        out << "";
        return out;
    }
    for (auto &t : o)
    {
        switch (t.type)
        {
        case NUM:
            out << t.num;
            break;
        case OP:
            out << static_cast<char>(t.op);
            break;

        case L_brackets:
            out << '(';
            break;
        case R_brackets:
            out << ')';
            break;
        }
    }
    return out;
}

std::vector<Token> tokenize(const std::string &expr)
{
    std::vector<Token> res;
    size_t index = 0;
    while (index < expr.size())
    {
        switch (expr[index])
        {
        case ADD:
        case SUB:
        case MUL:
        case DIV:
            res.push_back({.type = Token_type_t::OP,
                           .op = static_cast<op_t>(expr[index])});
            break;
        case '(':
        case ')':
            res.push_back({.type = (expr[index] == '(' ? Token_type_t::L_brackets : Token_type_t::R_brackets)});
            break;
        case ' ':
            break;
        default:
            size_t intend = index;
            while (std::isdigit(expr[intend]) and intend <= expr.size())
                intend++;
            const num_t num = std::stoi(expr.substr(index, intend - index));
            res.push_back({.type = Token_type_t::NUM, .num = num});
            index = intend - 1;
            break;
        }
        index++;
    }
    return res;
};

std::vector<Token> mid2repolan(const std::vector<Token> &expr)
{
    std::vector<Token> res;
    std::stack<Token> stk;
    for (auto &t : expr)
    {
        switch (t.type)
        {
        case NUM:
            res.push_back(t);
            break;
        case L_brackets:
            stk.push(t);
            break;
        case R_brackets:
            while (stk.top().type != L_brackets) // 一直出栈, 直到栈顶为'(
            {
                res.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
            break;
        case OP:
            while (not(stk.empty() or oplevel[stk.top().op] < oplevel[t.op]))
            {
                res.push_back(stk.top());
                stk.pop();
            };
            stk.push(t);
            break;
        }
    };
    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    };
    return res;
}

num_t evalrepolan(const std::vector<Token> &expr)
{
    std::stack<Token> stk;
    for (auto &t : expr)
    {
        switch (t.type)
        {
        case NUM:
            stk.push(t);
            break;
        case OP:
        {
            const num_t b = stk.top().num;
            stk.pop();
            const num_t a = stk.top().num;
            stk.pop();

            const num_t c = binoperators[t.op](a, b); // 实际计算位置
            stk.push({.type = NUM, .num = c});
            break;
        }
        default:
            throw "not a valid repolan expression";
            break;
        }
    }
    return stk.top().num;
}

num_t evalmid(const std::vector<Token> &expr)
{
    std::stack<Token> nums_stk, ops_stk;

    // 弹出两个数和一个操作符, 计算一下将结果压回去
    auto compute = [&]()
    {
        const op_t o = ops_stk.top().op;
        ops_stk.pop();
        const num_t b = nums_stk.top().num; // 先出栈的是运算符右侧的数
        nums_stk.pop();
        const num_t a = nums_stk.top().num; // 再出栈的是运算符左侧的数
        nums_stk.pop();
        const num_t c = binoperators[o](a, b);
        nums_stk.push({.type = NUM, .num = c});
    };

    for (auto t : expr)
    {
        switch (t.type)
        {
        case NUM:
            nums_stk.push({.type = NUM, .num = t.num});
            break;
        case OP:
            if (ops_stk.empty() or ops_stk.top().type == L_brackets or oplevel[t.op] > oplevel[ops_stk.top().op])
                // 如果当前操作符优先级大于栈顶操作符优先级
                // 或者栈顶为(
                // 或者栈空, 则操作符一定入栈;
                ops_stk.push({.type = OP, .op = t.op});
            else // 弹出两个操作数, 和一个操作符计算, 并将当前操作符压栈;
            {
                compute();
                ops_stk.push(t);
            }
            break;
        case L_brackets:
            ops_stk.push({.type = L_brackets});
            break;
        case R_brackets:
            // 一直弹出两个操作数, 和一个操作符计算,压结果, 直到遇到左括号
            while (ops_stk.top().type != L_brackets)
                compute();
            // 最终弹出左括号,子表达式计算完成
            ops_stk.pop();
            break;
        }
    }
    while (not ops_stk.empty())
        compute();

    return nums_stk.top().num;
};

int main(int argc, char *argv[])
{
    std::vector<std::pair<std::string, num_t>> testinputs{
        {"6+5*(8/4+7)", 51},
        {"3*4+5/2-6", 9},
        {"(8-4)/(5-3)", 2},
        {"(3+5)*(6-2)/4", 8},
        {"10*2/5+3-1", 6},
        {"1+2+3+4+5", 15},        // 连续多个加法
        {"1*2*3*4*5", 120},       // 连续多个乘法
        {"3*4+5/2-6*(8-4)", -13}, // 包含嵌套括号
        {"5+2*3*(4-1)/2", 11},    // 包含乘除法和括号
        {"(2*(3+4)-5)*6/2", 21},  // 包含嵌套括号和乘除法
        {"0", 0},                 // 单个数字
        {"(1+2*(3-4))/5", -1},    // 包含括号和负数
        {"(((((1+2)))))", 3},     // 多重嵌套括号
    };
    for (auto &[expr, ground_truth] : testinputs)
    {
        auto mid_expr = tokenize(expr);
        auto re_expr = mid2repolan(mid_expr);
        std::cout << mid_expr << std::endl;
        std::cout << re_expr << std::endl;

        std::cout << evalrepolan(re_expr) << std::endl;
        std::cout << evalmid(mid_expr) << std::endl;
    }
    return 0;
}