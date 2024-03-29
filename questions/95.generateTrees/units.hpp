/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-27 09:36:21
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include <iostream>
#include <ranges>
#include <tuple>
#include <vector>
using namespace std;
using InputType = tuple<int>;
using OutputType = tuple<vector<TreeNode *>>;

vector<InputType> TEST_UNIT_INPUT = {
    {3},
    {1},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {{
        BinaryTreeLayerOrder(1, Placeholder, 2, Placeholder, 3),
        BinaryTreeLayerOrder(1, Placeholder, 3, 2),
        BinaryTreeLayerOrder(2, 1, 3),
        BinaryTreeLayerOrder(3, 1, Placeholder, Placeholder, 2),
        BinaryTreeLayerOrder(3, 2, Placeholder, 1),
    }},
    {{
        BinaryTreeLayerOrder(1),
    }}};

inline bool compare(OutputType ground_truth, OutputType res)
{
    auto res1 = get<0>(ground_truth);
    auto res2 = get<0>(res);
    if (res1.size() != res2.size())
        return false;
    for (auto [p, q] : std::ranges::views::zip(res1, res2))
    {
        if (*p != *q)
            return false;
    }
    return true;
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