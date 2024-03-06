/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-04 17:27:37
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<string>;
using OutputType = tuple<string>;

vector<InputType> TEST_UNIT_INPUT = {
    {"babad"},
    {"cbbd"},
    {"a"},
    {"ac"},
    {"xaabacxcabaaxcabaax"},

};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {"bab"},
    {"bb"},
    {"a"},
    {"a"},
    {"xaabacxcabaax"},
};

bool compare(OutputType ground_truth, OutputType res)
{
    auto str1 = get<0>(ground_truth);
    auto str2 = get<0>(res);
    return str1 == str2;
}

std::ostream &
operator<<(std::ostream &out, const InputType &input)
{
    auto str1 = get<0>(input);
    out << str1;
    return out;
}