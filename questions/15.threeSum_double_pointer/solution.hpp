/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-08 21:40:34
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sol(vector<int> &nums)
    {
        auto res = vector<vector<int>>();
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) // 如果排完序之后最小的数都大于0, 返回空
            return res;
        for (int i_index = 0; i_index < nums.size(); i_index++)
        {
            // 固定 i_index, 在i_index右侧寻找目标数为 -nums[i_index] 的两个数 j 和 k;
            int left = i_index + 1, right = nums.size() - 1;
            if (i_index > 0 and nums[i_index] == nums[i_index - 1])
                continue;
            while (left < right)
            {
                int double_sum = nums[left] + nums[right];
                int target = -nums[i_index];
                if (double_sum < target)
                {
                    left++;
                }
                else if (double_sum > target)
                {
                    right--;
                }
                else
                {
                    res.push_back({nums[i_index], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return res;
    }
};