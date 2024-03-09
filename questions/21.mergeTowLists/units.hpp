/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 17:40:34
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "env.hpp"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<ListNode *, ListNode *>;
using OutputType = tuple<ListNode *>;

#define LIST(...) ListNodeHelper(__VA_ARGS__)
template <typename... Nums>
constexpr ListNode *ListNodeHelper(Nums... nums)
{
    int arr[] = {nums...};
    int size = sizeof...(nums);
    if (size == 0)
        return nullptr;
    return new ListNode(arr, size);
}

vector<InputType> TEST_UNIT_INPUT = {
    {LIST(1, 2, 4), LIST(1, 3, 4)},
    {LIST(), LIST()},
    {LIST(), LIST(0)},

};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {LIST(1, 1, 2, 3, 4, 4)},
    {LIST()},
    {LIST(0)},
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
}

inline std::ostream &operator<<(std::ostream &out, const InputType &input)
{
    out << "list1: " << get<0>(input) << endl;
    out << "list2: " << get<1>(input);
    return out;
}

inline std::ostream &operator<<(std::ostream &out, const OutputType &output)

{
    out << get<0>(output);
    return out;
}