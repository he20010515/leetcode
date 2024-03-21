/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-21 16:21:48
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
    bool sol(vector<int> &nums)
    {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                    return true;
            }
        }
        return false;
    };
};