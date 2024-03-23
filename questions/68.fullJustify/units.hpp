/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-23 17:48:29
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<vector<string>, int>;
using OutputType = tuple<vector<string>>;

vector<InputType> TEST_UNIT_INPUT = {
    {{"This", "is", "an", "example", "of", "text", "justification."},
     16},
    {{"What", "must", "be", "acknowledgment", "shall", "be"}, 16},
    {{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"}, 20},
};
vector<OutputType> TEST_UNIT_OUTPUT = {
    {{"This    is    an",
      "example  of text",
      "justification.  "}},
    {{"What   must   be",
      "acknowledgment  ",
      "shall be        "}},
    {{"Science  is  what we",
      "understand      well",
      "enough to explain to",
      "a  computer.  Art is",
      "everything  else  we",
      "do                  "}},
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