/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-21 21:43:19
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<vector<int>> &obstacleGrid)
    {
        // 动态规划 dp[i][j] 到达位置i,j有多少种走法?
        // base cases:
        // dp[0][0], 此处仅可能有一种走法;
        // dp[i][0], dp[0,j] 如果路途没有障碍物, 则只有一种
        // dp[i][j] = 0 if m[i][j] = 1 else
        // dp[i-1][j] + dp[i][j-1];
        const auto m = obstacleGrid.size();
        const auto n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 1; i < m; i++)
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
        for (int j = 1; j < m; j++)
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1];
        if (m == 1 or n == 1)
            return dp[m - 1][n - 1];

        // 状态转移方向, 左上到右下
        for (int i_add_j = 2; i_add_j < m + n - 1; i_add_j++)
        {
            for (int i = 1; i_add_j - i > 0; i++)
            {
                auto j = i_add_j - i;
                if (j >= n)
                    continue;
                if (i >= m)
                    continue;

                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};