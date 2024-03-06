/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-02 20:32:57
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
using InputType = tuple<vector<int>, int>;
using OutputType = tuple<vector<int>>;
vector<InputType> TEST_UNIT_INPUT = {
    {{2, 7, 11, 15}, 9},
    {{3, 2, 4}, 6},
    {{3, 3}, 6},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {{0, 1}},
    {{1, 2}},
    {{0, 1}},
};

bool compare(OutputType ground_truth, OutputType res)
{
    auto gt_ = get<0>(ground_truth);
    auto out_ = get<0>(res);
    if (gt_.size() != out_.size())
        return false;
    auto p = gt_.begin(), q = out_.begin();
    return gt_ == out_;
}

std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    auto vec_input = get<0>(input);
    auto target_num = get<1>(input);
    out << "seq: " << vec_input << "\t";
    out << "target num:" << target_num;
    return out;
}

std::ostream &operator<<(std::ostream &out, const OutputType &output)

{
    auto vec_output = get<0>(output);
    out << vec_output;
    return out;
}