/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-22 12:06:59
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<vector<int>> &grid)
    {
        const auto m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++)
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = grid[0][j] + dp[0][j - 1];

        for (int i_add_j = 2; i_add_j < m + n - 1; i_add_j++)
        {
            for (int i = 1; i_add_j - i > 0; i++)
            {
                auto j = i_add_j - i;
                if (j >= n)
                    continue;
                if (i >= m)
                    continue;

                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};