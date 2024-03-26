/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 21:53:44
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <cassert>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(vector<vector<char>> &matrix)
    {
        vector<int> reduce_line(matrix[0].size(), 0);
        int res = 0;
        for (int line = 0; line < matrix.size(); line++)
        {
            for (int j = 0; j < reduce_line.size(); j++)
            {
                if (matrix[line][j] == '0')
                    reduce_line[j] = 0;
                else
                    reduce_line[j]++;
            }
            res = max(res, maxHisRec(reduce_line));
        }
        return res;
    };
    int maxHisRec(vector<int> &line)
    {
        stack<int> stk;
        stk.push(-1);
        auto res = 0;
        for (int i = 0; i < line.size(); i++)
        {
            while (stk.top() != -1 and line[i] <= line[stk.top()])
            {
                auto height = line[stk.top()];
                stk.pop();
                auto width = i - stk.top() - 1;
                res = max(res, height * width);
            }
            stk.push(i);
        }
        while (stk.top() != -1)
        {
            int height = line[stk.top()];
            stk.pop();
            int width = line.size() - stk.top() - 1;
            res = max(res, height * width);
        }
        return res;
    }
};