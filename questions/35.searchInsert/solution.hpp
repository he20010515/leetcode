/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-15 12:07:20
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <utility>
#include <vector>

using namespace std;
class Solution
{
public:
    int sol(vector<int> nums, int target)
    {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0] < target ? 1 : 0;
        else if (target <= nums[0])
            return 0;

        int l = 0, r = nums.size();
        while ((r - l) > 1) // 左闭右开
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
            {
                l = mid;
            }
            else if (nums[mid] > target)
            {
                r = mid;
            }
            else
            {
                return mid;
            }
        }
        return r;
    };
};