/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-16 16:19:23
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <ostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool sol(string s, string p)
    {
        if (s.size() == 0)
        {
            for (auto &ch : p)
                if (ch != '*')
                    return false;
            return true;
        }
        if (p.size() == 0)
            return s.size() == 0;

        // 定义dp数组; dp函数定义如下: dp[i][j]表示字符串到i,表达式到[j]时是否匹配;
        auto dp = vector<vector<bool>>(s.size(), vector<bool>(p.size(), true));
        // 状态转移方程 dp[i][j] ==    dp[i-1][j-1]               // 如果p[j]  是普通字符, 且s[i]==s[j];
        //                        or dp[i-1][j-1]               // 如果p[j]  是'?'
        //                        or dp[i-1][j] or dp[i][j-1]   // 如果p[j]  是'*'

        // [i-1,j-1] [i-1,j]  i-1,j+1
        // [i  ,j-1] [i  ,j]  i  ,j+1
        //  i+1,j-1   i+1,j   i+1,j+1
        // 遍历方向应从左上角到右下角
        // fill base case;

        dp[0][0] = p[0] != '*' ? (p[0] == '?' ? true : p[0] == s[0]) : true;
        // dp[i,0] 情况下, i>=1时, 若p[0]是'*' true, 否则false
        for (int i = 1; i < s.size(); i++)
            dp[i][0] = p[0] == '*';
        // dp[0,j] 情况下, j>=1时, 考虑p只能匹配s[0]这个单个字符;

        bool firstchar_matched = p[0] != '*';
        for (int j = 1; j < p.size(); j++)
        {
            switch (p[j])
            {
            case '*':
                dp[0][j] = dp[0][j - 1];
                break;
            case '?':
                if (firstchar_matched)
                    dp[0][j] = false;
                else
                    dp[0][j] = true;
                firstchar_matched = true;
                break;
            default:
                if (not firstchar_matched)
                    dp[0][j] = p[j] == s[0];
                else
                    dp[0][j] = false;
                firstchar_matched = true;
            }
        }
        for (int i_add_j = 2; i_add_j <= (s.size() + p.size() - 2); i_add_j++)
        {
            // i + j = i_add_j;
            // ibegin = max(1,i_add_j - s.size());
            auto ibengin = std::max(1, static_cast<int>(i_add_j - p.size()));
            for (int i = ibengin; i < s.size(); i++)
            {
                auto j = i_add_j - i;
                if (j <= 0)
                    break;
                switch (p[j])
                {
                case '*':
                    dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
                    break;
                case '?':
                    dp[i][j] = dp[i - 1][j - 1];
                    break;
                default:
                    if (s[i] == p[j])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                    break;
                }
            }
        }
        return dp[s.size() - 1][p.size() - 1];
    }
};