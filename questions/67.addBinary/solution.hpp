/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-23 17:17:07
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string sol(string a, string b)
    {
        if (a == "0")
            return b;
        else if (b == "0")
            return a;
        bool upper = false;
        const auto maxlen = max(a.length(), b.length());
        const auto a_len = a.length(), b_len = b.length();
        vector<char> buffer(maxlen + 1, '0');

        for (int index = maxlen; index >= 0; index--)
        {
            const int r_pos = index;
            const int a_pos = index + a_len - maxlen - 1;
            const int b_pos = index + b_len - maxlen - 1;

            const bool a_bit = a_pos >= 0 ? a[a_pos] == '1' : false;
            const bool b_bit = b_pos >= 0 ? b[b_pos] == '1' : false;
            buffer[index] = (a_bit xor b_bit) xor upper ? '1' : '0';
            upper = (a_bit and b_bit) or (a_bit and upper) or (b_bit and upper);
        }
        if (buffer[0] == '1')
            return string(buffer.begin(), buffer.end());
        else
            return string(++buffer.begin(), buffer.end());
    }
};