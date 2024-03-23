/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-23 15:17:22
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <regex>
#include <string>

using namespace std;
class Solution
{
private:
    static const regex reg;

public:
    bool sol(string s)
    {

        return regex_match(s, reg);
    };
};

const string reg_point_float = R"([\+\-]?(\d+\.\d+|\.\d+|\d+\.))"; // 匹配 x. .x x.x
const string reg_signed_int = R"([\+\-]?\d+)";
const string reg_number = "^(" + reg_signed_int + "|" + reg_point_float + ")([eE]" + reg_signed_int + ")?$";
const regex Solution::reg = regex(reg_number);