/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-27 16:12:10
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool sol(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        //* dp[i][j] 表示 s1[0:i), 和s2[0:j)是否构成s3[0:i+j)的交错;
        dp[0][0] = true;
        for (int i = 1; i <= s1.size(); i++)
            dp[i][0] = (s1[i - 1] == s3[i - 1]);
        for (int j = 1; j <= s2.size(); j++)
            dp[0][j] = (s2[j - 1] == s3[j - 1]);

        // 状态转移方程

        // dp[i][j] = dp[i][j-1] and s2[j] = s3[i+j]; // 匹配串2;
        //         or dp[i-1][j] and s1[i] = s3[i+j]; // 匹配串1;
        for (int i = 1; i <= s1.size(); i++)
            for (int j = 1; j <= s2.size(); j++)
                dp[i][j] = (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]) or
                           (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]);
        return dp[s1.size()][s2.size()];
    }
};