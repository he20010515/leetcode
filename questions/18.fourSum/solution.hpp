/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 15:17:09
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <cstddef>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sol(vector<int> nums, int target)
    {
        if (nums.size() < 4)
            return {};
        else if (nums.size() == 4)
        {
            if (static_cast<long long>(nums[0]) + static_cast<long long>(nums[1]) + static_cast<long long>(nums[2]) + static_cast<long long>(nums[3]) == target)
                return {nums};
            else
                return {};
        }
        auto ans = vector<vector<int>>();
        sort(nums.begin(), nums.end());
        for (int a_index = 0; a_index < nums.size() - 3; a_index++)
        {
            if (a_index > 0 and nums[a_index] == nums[a_index - 1]) // and a_index < nums.size() - 3)
                continue;
            // 三数之和问题, targetnum 为 target-nums[a_index];
            for (int b_index = a_index + 1; b_index < nums.size() - 2; b_index++)
            {
                int left = b_index + 1, right = nums.size() - 1;
                if (b_index > a_index + 1 and nums[b_index] == nums[b_index - 1]) // and b_index < nums.size() - 2)
                    continue;
                while (left < right)
                {
                    long long cursum = static_cast<long long>(nums[a_index]) + nums[b_index] + nums[left] + nums[right];
                    if (cursum > target)
                        right--;
                    else if (cursum < target)
                        left++;
                    else
                    {
                        ans.push_back(
                            {
                                nums[a_index],
                                nums[b_index],
                                nums[left],
                                nums[right],
                            });
                        right--;
                        left++;
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }

        return ans;
    }
};