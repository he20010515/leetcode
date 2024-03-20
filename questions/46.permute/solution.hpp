/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-20 19:06:25
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
    vector<vector<int>> sol(vector<int> nums)
    {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> avaliable(nums.size(), true);
        dp(nums, res, cur, avaliable);
        return res;
    }
    bool dp(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur, vector<bool> avaliable)
    {
        if (cur.size() == nums.size())
        {
            res.push_back(cur);
            return true;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!avaliable[i])
                continue;

            cur.push_back(nums[i]);
            avaliable[i] = false;
            dp(nums, res, cur, avaliable);
            avaliable[i] = true;
            cur.pop_back();
        }
        return true;
    }
};