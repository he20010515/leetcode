/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-10 22:44:11
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<vector<int>>;
using OutputType = tuple<vector<int>, int>;

vector<InputType> TEST_UNIT_INPUT = {
    {{1, 1, 2}},
    {{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}},
    {{0, 0}},
    {{1, 1}},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {{1, 2}, 2},
    {{0, 1, 2, 3, 4}, 5},
    {{0}, 1},
    {{1}, 1},

};

inline bool compare(OutputType ground_truth, OutputType res)
{
    auto k = get<1>(res);
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
    out << get<0>(input);
    return out;
}

inline std::ostream &operator<<(std::ostream &out, const OutputType &output)

{
    out << get<0>(output);
    return out;
}