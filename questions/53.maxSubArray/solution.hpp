/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-21 14:33:28
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        // dp[i] == 以nums[i]结尾的最大子串和
        auto dp = vector<int>(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            if (dp[i - 1] <= 0)
                dp[i] = nums[i];
            else
                dp[i] = dp[i - 1] + nums[i];

        int res = std::numeric_limits<int>::min();
        for (auto d : dp)
            res = max(d, res);
        return res;
    }
};