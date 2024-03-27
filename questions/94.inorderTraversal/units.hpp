/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 21:26:45
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
using OutputType = tuple<vector<int>>;

vector<InputType> TEST_UNIT_INPUT = {
    {BinaryTreeLayerOrder(1, Placeholder, 2, 3)},
    {BinaryTreeLayerOrder()},
    {BinaryTreeLayerOrder(1)},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {{1, 3, 2}},
    {{}},
    {{1}},
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