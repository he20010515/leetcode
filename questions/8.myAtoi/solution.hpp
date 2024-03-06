/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-06 00:05:08
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cmath>
#include <limits>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(string s)
    {
        auto buffer = vector<int>();
        int sign = 1;
        long res = 0;
        const int32_t tens[10] = {
            1,
            10,
            100,
            1000,
            10000,
            100000,
            1000000,
            10000000,
            100000000,
            1000000000,
        };
        auto flag_sign_end = false, flag_num_begin = false, flag_black_end = false;
        auto ch = s.begin();
        while (*ch == ' ' and ch != s.end())
            ch++;
        if ((*ch == '+' or *ch == '-') and ch != s.end())
        {
            if (*ch == '-')
                sign = -sign;
            ch++;
        }
        while (*ch == '0')
            ch++;

        while ('0' <= *ch and *ch <= '9' and ch != s.end())
        {
            buffer.push_back(*ch - '0');
            ch++;
        }
        auto e = 0;
        for (auto p = buffer.rbegin(); p != buffer.rend(); p++, e++)
        {
            if (e >= 10)
                if (sign > 0)
                    return std::numeric_limits<int>::max();
                else
                    return std::numeric_limits<int>::min();
            res += (long)*p * (long)tens[e];
        }

        res = res * sign;
        if (res >= std::numeric_limits<int>::max())
            return std::numeric_limits<int>::max();
        if (res <= std::numeric_limits<int>::min())
            return std::numeric_limits<int>::min();
        return res;
    };
};