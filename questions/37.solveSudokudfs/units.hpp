/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-15 21:51:47
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<vector<vector<char>>>;
using OutputType = tuple<vector<vector<char>>>;

vector<InputType> TEST_UNIT_INPUT = {
    // {{
    //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    // }},

    {{
        {'.', '.', '9', '7', '4', '8', '.', '.', '.'},
        {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '2', '.', '1', '.', '9', '.', '.', '.'},
        {'.', '.', '7', '.', '.', '.', '2', '4', '.'},
        {'.', '6', '4', '.', '1', '.', '5', '9', '.'},
        {'.', '9', '8', '.', '.', '.', '3', '.', '.'},
        {'.', '.', '.', '8', '.', '3', '.', '2', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '6'},
        {'.', '.', '.', '2', '7', '5', '9', '.', '.'},
    }}};
vector<OutputType> TEST_UNIT_OUTPUT = {
    // {{
    //     {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
    //     {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
    //     {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
    //     {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
    //     {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
    //     {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
    //     {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
    //     {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
    //     {'3', '4', '5', '2', '8', '6', '1', '7', '9'},
    // }},
    {},

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