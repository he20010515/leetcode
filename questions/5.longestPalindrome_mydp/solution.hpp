/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-05 14:52:07
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
using namespace std;
class Solution
{
public:
    string sol(string s)
    {

        auto len = s.length();
        if (len == 0 or len == 1)
            return s;

        auto dp = vector<vector<bool>>(len, vector<bool>(len, false));
        // dp[i][j] 表示 str[i:j]是否是回文串

        // 状态转移方程: dp[i][j] = dp[i+1][j-1] and dp[i] == dp[j]

        auto maxlen = 0, j = 0, flagi = 0;
        // 处理边界条件
        for (size_t i = 0; i < len; i++)
        {
            dp[i][i] = true; // 长度为1的字符串是回文
            maxlen = maxlen > 1 ? maxlen : 1;
            if (s[i] == s[i + 1] and i + 1 < len)
            {
                maxlen = 2;
                flagi = i;
                dp[i][i + 1] = true; // 长度为2的字符串字母相同时为回文
            }
        }

        // 记录最大回文子串

        // 枚举子串长度
        for (size_t sublen = 3; sublen <= len; sublen++)
        {
            // 枚举左边界
            for (size_t i = 0; i < len; i++)
            {
                // 由sublen和左边界确定右边界位置
                j = sublen + i - 1;
                if (j >= len) // 越界退出
                    break;
                if (s[i] != s[j]) // 此处应用状态转移方程
                    dp[i][j] = false;
                else
                    dp[i][j] = dp[i + 1][j - 1];

                if (dp[i][j] and j - i + 1 > maxlen) // 记录最大回文子串
                {
                    maxlen = j - i + 1;
                    flagi = i;
                }
            };
        }
        // std::cout << dp << std::endl;
        return s.substr(flagi, maxlen);
    };
};