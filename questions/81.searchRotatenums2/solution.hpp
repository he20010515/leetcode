/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 13:39:49
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
    bool sol(vector<int> &nums, int target)
    {
        return binarySearch(nums, 0, nums.size(), target);
    };
    // 严格左闭右开二分搜索
    bool binarySearch(const vector<int> &nums, const int l, const int r, const int target)
    {
        if (l == r or l + 1 == r)
            return nums[l] == target;

        int mid = (r + l) / 2;
        if (nums[l] < nums[r - 1]) // 如果左端点严格小于右端点, 说明[l,r)是单调递增区间, 进行普通二分搜索;
        {
            if (target < nums[mid])
                return binarySearch(nums, l, mid, target);
            else if (target > nums[mid])
                return binarySearch(nums, mid, r, target);
            else
                return true;
        }
        else // 否则两端都要搜索;
        {
            return binarySearch(nums, l, mid, target) or binarySearch(nums, mid, r, target);
        }
    }
};