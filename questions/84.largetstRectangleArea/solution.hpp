/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 15:03:22
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<int> &heights)
    {
        stack<int> stk;
        stk.push(-1); // 负元素;
        int res = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (stk.top() != -1 and heights[i] <= heights[stk.top()]) // 出栈
            {
                int height = heights[stk.top()];
                stk.pop();
                int width = i - stk.top() - 1;
                int area = height * width;
                res = max(area, res);
            }
            stk.push(i);
        };

        while (stk.top() != -1)
        {
            int height = heights[stk.top()];
            stk.pop();
            int width = heights.size() - stk.top() - 1;
            int area = height * width;
            res = max(area, res);
        }
        return res;
    }
};