/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-30 21:09:26
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<TreeNode *>;
using OutputType = tuple<vector<vector<int>>>;

vector<InputType> TEST_UNIT_INPUT = {
    {BinaryTreeLayerOrder(1, 2, 2, 3, 4, 4, 3)},
    {BinaryTreeLayerOrder(1, 2, 2, Placeholder, 3, Placeholder, 3)},
    {BinaryTreeLayerOrder(3, 9, 20, Placeholder, Placeholder, 15, 7)}};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {{
        {1},
        {2, 2},
        {3, 4, 4, 3},
    }},
    {
        {
            {1},
            {2, 2},
            {3, 3},
        },
    },
    {{
        {3},
        {20, 9},
        {15, 7},
    }}};

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