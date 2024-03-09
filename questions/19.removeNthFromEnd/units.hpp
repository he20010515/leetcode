/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-09 15:28:23
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 15:45:17
 * @FilePath: /leetcode/questions/19.removeNthFromEnd/units.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "env.hpp"
#include <atomic>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<ListNode *, int>;
using OutputType = tuple<ListNode *>;

// 342+456 = 708;

vector<InputType> TEST_UNIT_INPUT = {
    {new ListNode(new int[5]{1, 2, 3, 4, 5}, 5), 2},
    {new ListNode(new int[1]{1}, 1), 1},
    {new ListNode(new int[2]{1, 2}, 2), 1},

};

vector<OutputType> TEST_UNIT_OUTPUT = {
    {{new ListNode(new int[4]{1, 2, 3, 5}, 4)}},
    {{nullptr}},
    {{new ListNode(new int[1]{1}, 1)}},

};

inline std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    auto a = get<0>(input);
    out << "a: " << a << "\t";
    return out;
}

inline bool compare(OutputType ground_truth, OutputType res)
{
    auto gt_ = get<0>(ground_truth);
    auto out_ = get<0>(res);
    if (gt_ and out_)
    {
        return *gt_ == *out_;
    }
    else if (gt_ == nullptr and out_ == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}