/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-10 22:46:16
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
public:
    tuple<vector<int>, int> sol(vector<int> &nums)
    {
        if (nums.size() < 2)
            return {nums, nums.size()};
        int fast = 0, slow = 0;
        const int size = nums.size();
        while (fast != size)
        {
            while (fast + 1 < size and nums[fast] == nums[fast + 1])
                fast++;
            nums[slow] = nums[fast];
            fast++;
            slow++;
        };
        return {nums, slow};
    };
};