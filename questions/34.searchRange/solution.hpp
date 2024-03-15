/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-15 11:48:15
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
    vector<int> sol(vector<int> nums, int target)
    {
        if (nums.size() == 1)
            if (nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        else if (nums.size() == 0)
            return {-1, -1};

        return binarySearch(0, nums.size(), target, nums);
    };
    vector<int> binarySearch(int l, int r, int target, vector<int> &nums)
    {
        if ((l == r or l + 1 == r) and (nums[l] != target))
            return {-1, -1};
        else if ((l == r or l + 1 == r) and (nums[l] != target))
            return {l, l};

        int mid = (l + r) / 2;
        if (nums[mid] > target) // 说明target区间在左侧
        {
            return binarySearch(l, mid, target, nums);
        }
        else if (nums[mid] < target)
        { // target区间在右侧
            return binarySearch(mid, r, target, nums);
        }
        else // nums[mid] == target;
        {
            return {searchl(l, mid, target, nums), searchr(mid, r, target, nums)};
        };
    };
    int searchl(int l, int r, int target, vector<int> &nums)
    {
        // assert nums[r-1]==target;
        if ((l == r or l + 1 == r) and (nums[l] == target or nums[r] == target))
            return nums[l] == target ? l : r;
        else
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return searchl(l, mid, target, nums);
            else
                return searchl(mid, r, target, nums);
        }
    }
    int searchr(int l, int r, int target, vector<int> &nums)
    {
        // assert nums[l]==target;
        if ((l == r or l + 1 == r) and (nums[l] == target))
            return l;
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return searchr(mid, r, target, nums);
            else
                return searchr(l, mid, target, nums);
        }
    }
};