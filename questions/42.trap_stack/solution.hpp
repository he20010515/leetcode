/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-19 15:29:47
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<int> &height)
    {
        int ans = 0;
        stack<int> stk;
        const int N = height.size();
        for (int i = 0; i < N; i++)
        {
            while (!stk.empty() and height[i] > height[stk.top()])
            {
                auto top = stk.top();
                stk.pop();
                if (stk.empty())
                    break;
                auto left = stk.top();
                auto curWidth = i - left - 1;
                auto curHeight = min(height[left], height[top]) - height[i];
                ans += curWidth * curHeight;
            };
            stk.push(i);
        };
        return ans;
    }
};