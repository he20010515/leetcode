/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-26 14:02:54
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-05 21:00:54
 * @FilePath: /leetcode/quentions/1.twosum/tests.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using InputType = tuple<int>;
using OutputType = tuple<double>;

vector<InputType> TEST_UNIT_INPUT = {};
vector<OutputType> TEST_UNIT_OUTPUT = {};

bool compare(OutputType ground_truth, OutputType res) { return true; }

inline std::ostream &operator<<(std::ostream &out, const InputType &input) {
  return out;
}

inline std::ostream &operator<<(std::ostream &out, const OutputType &output)

{
  return out;
}