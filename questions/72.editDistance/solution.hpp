/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-24 15:24:30
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(string word1, string word2)
    {
        const auto m = word1.size(), n = word2.size();
        if (m * n == 0)
            return m + n;
        // 常规dp
        // auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        // for (int i = 0; i <= m; i++)
        //     dp[i][0] = i;
        // for (int j = 0; j <= n; j++)
        //     dp[0][j] = j;
        // // 遍历dp, 状态转移
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         if (word1[i - 1] == word2[j - 1]) // 注意, dp.shape [m+1,n+1]
        //             dp[i][j] = dp[i - 1][j - 1];
        //         else
        //             dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
        //     }
        // }

        // 滚动dp,

        auto dp_roll1 = vector<int>(m + 1, 0);
        auto dp_roll2 = vector<int>(m + 1, 0);
        auto &ref1 = dp_roll1, &ref2 = dp_roll2;
        for (int i = 0; i <= m; i++)
            ref1[i] = i;
        for (int j = 1; j <= n; j++)
        {
            for (int i = 0; i <= m; i++)
            {
                if (i == 0)
                    ref2[i] = j;
                else
                {
                    if (word1[i - 1] == word2[j - 1])
                        ref2[i] = ref1[i - 1];
                    else
                        ref2[i] = 1 + min(ref2[i - 1], min(ref1[i - 1], ref1[i]));
                }
            };
            swap(ref1, ref2);
        }
        return ref1[m];
    };
};