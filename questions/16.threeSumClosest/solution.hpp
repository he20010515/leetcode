/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-08 22:10:18
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int sol(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        if (nums.size() == 3)
            return res;

        for (int i_index = 0; i_index < nums.size(); i_index++)
        {
            int left = i_index + 1, right = nums.size() - 1;
            while (left < right)
            {
                int cur = nums[i_index] + nums[left] + nums[right];
                int dis = target - cur;
                if (abs(dis) < abs(target - res))
                    res = cur;
                if (dis < 0) // 说明cur偏大, 右指针左移
                {
                    right--;
                }
                else if (dis > 0)
                {
                    left++;
                }
                else
                {
                    return target;
                }
            }
        }

        return res;
    }
};