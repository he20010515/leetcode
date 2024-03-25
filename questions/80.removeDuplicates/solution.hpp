/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 13:27:06
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
private:
    int m, n;

public:
    int sol(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return nums.size();
        }
        int fast = 0, slow = 0;
        while (fast < nums.size())
        {
            while (fast < nums.size() - 2 and nums[fast] == nums[fast + 1] and
                   nums[fast] == nums[fast + 2])
                fast++;
            nums[slow] = nums[fast];
            slow++;
            fast++;
        }
        return slow;
    };
};