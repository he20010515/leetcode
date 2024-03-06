/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-05 14:53:38
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-05 14:55:30
 * @FilePath: /leetcode/questions/5.longestPalindrome_fastest_offical/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "basic.hpp"
using namespace std;
class Solution
{
public:
    string sol(string s)
    {

        string res;
        for (int i = 0; i < s.size(); i++)
        {
            int a = i, b = i + 1;
            while (a >= 0 && b < s.size() && s[a] == s[b])
            {
                a--;
                b++;
            }
            if (b - a - 1 > res.size())
                res = s.substr(a + 1, b - a - 1);
            a = i - 1, b = i + 1;
            while (a >= 0 && b < s.size() && s[a] == s[b])
            {
                a--;
                b++;
            }

            if (b - a - 1 > res.size())
                res = s.substr(a + 1, b - a - 1);
        }
        return res;
    }
};