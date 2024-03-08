/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-08 21:27:55
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
using InputType = tuple<vector<int>>;
using OutputType = tuple<vector<vector<int>>>;

vector<InputType> TEST_UNIT_INPUT = {
    {{-1, 0, 1, 2, -1, -4}},
    {{0, 1, 1}},
    {{0, 0, 0}},
    {{-1, 0, 1, 0}},
    {{-2, 0, 0, 2, 2}},
};

vector<OutputType>
    TEST_UNIT_OUTPUT = {
        {{{-1, 0, 1}, {-1, -1, 2}}},
        {{}},
        {{{0, 0, 0}}},
        {{{-1, 0, 1}}},
        {{{-2, 0, 2}}},
};

inline bool compare(OutputType ground_truth, OutputType res)
{
    auto A = unordered_set<tuple<int, int, int>, MyTupleHash<2, int, int, int>>();
    auto B = unordered_set<tuple<int, int, int>, MyTupleHash<2, int, int, int>>();
    for (auto threenum : get<0>(ground_truth))
    {
        sort(threenum.begin(), threenum.end());
        A.insert(make_tuple(threenum[0], threenum[1], threenum[2]));
    };
    for (auto threenum : get<0>(res))
    {
        sort(threenum.begin(), threenum.end());
        B.insert(make_tuple(threenum[0], threenum[1], threenum[2]));
    };

    return A == B;
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