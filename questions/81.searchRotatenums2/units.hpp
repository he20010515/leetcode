/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 13:30:29
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using InputType = tuple<vector<int>, int>;
using OutputType = tuple<bool>;

vector<InputType> TEST_UNIT_INPUT = {
    {{2, 5, 6, 0, 0, 1, 2}, 0},
    {{2, 5, 6, 0, 0, 1, 2}, 3},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {true},
    {false},
};

inline bool compare(OutputType ground_truth, OutputType res)
{

    return get<0>(ground_truth) == get<0>(res);
}

inline std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    out << get<0>(input);
    return out;
}

inline std::ostream &operator<<(std::ostream &out, const OutputType &output)

{
    out << get<0>(output);
    return out;
}