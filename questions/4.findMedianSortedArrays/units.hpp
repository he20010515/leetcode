/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-04 11:26:50
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<vector<int>, vector<int>>;
using OutputType = tuple<double>;

vector<InputType> TEST_UNIT_INPUT = {
    {{1, 3}, {2}},
    {{1, 2}, {3, 4}},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {2.0},
    {2.5},
};

bool compare(OutputType ground_truth, OutputType res)
{
    auto gt = get<0>(ground_truth);
    auto re = get<0>(res);

    return (gt - re) < 0.1;
}

std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    vector<int> vec1 = get<0>(input);
    vector<int> vec2 = get<1>(input);

    out << "vec1:" << vec1 << '\t' << "vec2:" << vec2;
    return out;
}

std::ostream &operator<<(std::ostream &out, const OutputType &output)
{
    out << get<0>(output);
    return out;
}