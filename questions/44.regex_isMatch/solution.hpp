/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-16 14:28:19
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <vector>
using namespace std;

#define UNKNOWN 2

class Solution
{
public:
    bool sol(string s, string p)
    {
        auto memo = vector<vector<int>>(s.size() + 1, vector<int>(p.size() + 1, UNKNOWN));
        return dp(0, 0, s, p, memo); // i 到 end, j 到end 是否匹配?
    }
    bool dp(int i, int j, const string &s, string &p, vector<vector<int>> &memo) //
    {
        if (memo[i][j] != UNKNOWN) // short hand
            return memo[i][j];

        // base case:
        if (i == s.size()) // 字符串匹配完了
        {
            if (j == p.size()) // 如果此时表达式也完了, 则是最好的情况, 字符串匹配成功
                return true;
            else // 否则后面的表达式必须匹配空串, 也就是说必须全是*
            {
                for (int t = j; j < p.size(); j++)
                    if (p[j] != '*')
                        return false;
                return true;
            }
        }
        else if (j == p.size())
            return false;

        // dp:
        switch (p[j])
        {
        case '*': // 匹配多个或者匹配0个
            return dp(i + 1, j, s, p, memo) or dp(i, j + 1, s, p, memo);
            break;
        case '?':
            return dp(i + 1, j + 1, s, p, memo);
            break;
        default:
            if (s[i] == p[j])
                return dp(i + 1, j + 1, s, p, memo);
            else
            {
                memo[i][j] = false;
                return false;
            }
            break;
        }
        memo[i][j] = false;
        return false;
    }
};