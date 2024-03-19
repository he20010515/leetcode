/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-19 15:11:57
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<int> &height)
    {
        auto Lmax = vector<int>(height.size(), 0);
        auto Rmax = vector<int>(height.size(), 0);

        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0)
                Lmax[i] = height[0];
            else
                Lmax[i] = max(Lmax[i - 1], height[i]);
        }
        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (i == height.size() - 1)
                Rmax[i] = height[height.size() - 1];
            else
                Rmax[i] = max(Rmax[i + 1], height[i]);
        }
        int ans = 0, bound;
        for (int i = 0; i < height.size(); i++)
        {
            bound = min(Lmax[i], Rmax[i]) - height[i];
            ans += max(bound, 0);
        }

        return ans;
    }
};