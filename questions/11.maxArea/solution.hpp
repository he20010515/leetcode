/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-06 17:25:00
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
    int sol(vector<int> &height)
    {
        int res = 0;
        int p = 0, q = height.size() - 1;
        auto max = [](int a, int b)
        { return a > b ? a : b; };
        auto min = [](int a, int b)
        { return a < b ? a : b; };

        while (p != q)
        {
            res = max(res, (q - p) * min(height[p], height[q]));
            if (height[p] < height[q])
                p++;
            else
                q--;
        };
        return res;
    }
};