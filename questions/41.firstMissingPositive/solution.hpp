/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-18 21:12:25
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
    int sol(vector<int> &nums)
    {
        // 遍历第一次, 把太大的和太小的数置为0;
        const int nums_size = nums.size();

        for (int i = 0; i < nums_size; i++)
        {
            if (nums[i] < 0 or nums[i] > nums_size)
                nums[i] = 0;
        }

        // 遍历第二次, 把数字i放到第i个位置上;
        for (int i = 0; i < nums_size; i++)
        {
            if (nums[i] == 0) // 我们不care已经是0的数了;
                continue;
            // 比如此时nums[i]是3, 我们应该把这个3放到num[3-1]上;
            while (!(nums[i] == 0 or nums[i] == i + 1 or nums[nums[i] - 1] == nums[i]))
                std::swap(nums[i], nums[nums[i] - 1]);
        }
        // 遍历第三次, 第一个空就是我们要的解, 如果都没有的话, 那就是缺少num_size;
        for (int i = 0; i < nums_size; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums_size + 1;
    }
};