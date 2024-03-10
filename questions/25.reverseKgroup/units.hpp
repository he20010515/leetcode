/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-10 22:06:28
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "env.hpp"
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using InputType = tuple<ListNode *, int>;
using OutputType = tuple<ListNode *>;

vector<InputType> TEST_UNIT_INPUT = {
    {LIST(1, 2, 3, 4, 5), 2},
    {LIST(1, 2, 3, 4, 5, 6, 7, 8), 3},
    {LIST(1), 1},

};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {LIST(2, 1, 4, 3, 5)},
    {LIST(3, 2, 1, 6, 5, 4, 7, 8)},
    {LIST(1)},
};

inline bool compare(OutputType ground_truth, OutputType res)
{
    auto p = get<0>(ground_truth), q = get<0>(res);
    if (p == nullptr and q == nullptr)
        return true;
    else if (p != nullptr and q != nullptr)
        return *p == *q;
    else
        return false;
    ;
}

inline std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    out << get<0>(input);
    return out;
}

// inline std::ostream &operator<<(std::ostream &out, const OutputType &output)

// {
//     out << get<0>(output);
//     return out;
// }