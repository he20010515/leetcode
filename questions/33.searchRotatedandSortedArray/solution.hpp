/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-14 17:43:02
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"

using namespace std;
class Solution
{
public:
    int sol(vector<int> nums, int target)
    {
        // [l,r) 左闭右开
        return bicut(0, nums.size(), nums, target);
    };
    int bicut(int l, int r, vector<int> &nums, int target)
    {
        if (l + 1 == r or l == r) // 递归出口
        {
            if (nums[l] == target)
                return l;
            else
                return -1;
        }
        int mid = (l + r) / 2;
        if (nums[l] > nums[r - 1]) // 如果不是递增区间, 两侧都要搜索
        {
            auto left = bicut(l, mid, nums, target);
            auto right = bicut(mid, r, nums, target);
            if (left >= 0 and right < 0)
                return left;
            else if (left < 0 and right >= 0)
                return right;
            else
                return -1;
        }
        else
        { // 是递增区间的话, 只需要搜索一侧
            if (nums[mid] == target)
                return mid;
            else if (target < nums[mid])
                return bicut(l, mid, nums, target);
            else
                return bicut(mid, r, nums, target);
        }
    };
};