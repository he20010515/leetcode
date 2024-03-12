/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-11 20:36:27
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
    tuple<vector<int>, int> sol(vector<int> &nums, int val)
    {
        auto fast = 0, slow = 0;
        while (fast < nums.size())
        {
            while (fast < nums.size() and nums[fast] == val)
                fast++;
            if (fast == nums.size())
                break;
            nums[slow] = nums[fast];
            slow++, fast++;
        }
        return make_tuple(nums, slow);
    }
};