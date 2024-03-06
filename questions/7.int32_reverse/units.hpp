/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-05 21:07:09
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <tuple>
#include <vector>

#pragma once
using namespace std;
using InputType = tuple<int>;
using OutputType = tuple<int>;
vector<InputType> TEST_UNIT_INPUT = {
    {123},
    {-123},
    {0},
    {1534236469},
    {-2147483648},
    {1563847412},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {321},
    {-321},
    {0},
    {0},
    {0},
    {0},
};

inline bool compare(OutputType ground_truth, OutputType res)
{
    return get<0>(res) == get<0>(ground_truth);
}

inline std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    out << get<0>(input);
    return out;
}
