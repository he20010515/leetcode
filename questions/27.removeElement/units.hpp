/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-11 20:36:09
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <iostream>
#include <ostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<vector<int>, int>;
using OutputType = tuple<vector<int>, int>;

vector<InputType> TEST_UNIT_INPUT = {
    {{3, 2, 2, 3}, 3},
    {{0, 1, 2, 2, 3, 0, 4, 2}, 2},
    {{3, 3}, 5},

};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {{2, 2}, 2},
    {{0, 1, 3, 0, 4}, 5},
    {{3, 3}, 2},
};

inline bool compare(OutputType ground_truth, OutputType res)
{
    auto k = get<1>(ground_truth);
    auto real_k = get<1>(res);
    if (k != real_k)
        return false;
    for (int i = 0; i < k; i++)
    {
        if (get<0>(ground_truth)[i] == get<0>(res)[i])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

inline std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    auto [vec, size_or_tar] = input;
    out << "nums  : " << vec << std::endl
        << "tarval: " << size_or_tar;

    return out;
}
