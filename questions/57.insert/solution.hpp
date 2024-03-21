/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-21 16:54:02
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
    vector<vector<int>> sol(vector<vector<int>> &intervals)
    {
        auto comp = [](const vector<int> inter1, const vector<int> inter2)
        {
            return inter1[0] < inter2[0];
        };

        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> res;
        for (int i = 0; i < intervals.size(); i++)
        {
            vector<int> cur(intervals[i]);
            while (i < intervals.size() - 1 and intervals[i + 1][0] <= cur[1])
            {
                cur[1] = max(intervals[i + 1][1], cur[1]);
                i++;
            }
            res.push_back(cur);
        }
        return res;
    }
};