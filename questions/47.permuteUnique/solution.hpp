/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-20 19:42:38
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <array>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sol(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> vis(nums.size(), false);
        vector<int> buffer;
        dp(nums, res, vis, buffer);
        return res;
    }
    bool dp(vector<int> &nums, vector<vector<int>> &res, vector<bool> &vis, vector<int> &buffer)
    {
        if (buffer.size() == nums.size())
        {
            res.push_back(buffer);
            return true;
        }
        for (int k = 0; k < nums.size(); k++)
        {
            if (vis[k])
                continue;
            if (k > 0 and nums[k - 1] == nums[k] and !vis[k - 1])
                continue;

            vis[k] = true;
            buffer.push_back(nums[k]);
            dp(nums, res, vis, buffer);
            buffer.pop_back();
            vis[k] = false;
        }
        return true;
    }
};