/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-03 16:29:52
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-04 10:16:44
 * @FilePath: /leetcode/questions/3.lengthOfLongestSubstring/units.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using InputType = tuple<string>;
using OutputType = tuple<int>;

vector<InputType> TEST_UNIT_INPUT = {
    {"abcabcbb"},
    {"bbbbb"},
    {"pwwkew"},
    {" "},
    {"aab"},
    {""},
    {"hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"},
};

vector<OutputType> TEST_UNIT_OUTPUT = {
    {3},
    {1},
    {3},
    {1},
    {2},
    {0},
    {55},
};

bool compare(OutputType ground_truth, OutputType res)
{
    auto gt_ = get<0>(ground_truth);
    auto out_ = get<0>(res);
    return gt_ == out_;
}

std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    auto _string = get<0>(input);
    out << _string;
    return out;
}

std::ostream &operator<<(std::ostream &out, const OutputType &output)

{
    auto res = get<0>(output);
    out << res;
    return out;
}