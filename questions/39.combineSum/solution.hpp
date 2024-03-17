/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-17 14:19:18
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sol(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> buffer;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, buffer, res, 0);
        return res;
    };
    bool dfs(vector<int> &candidates, int target, vector<int> &buffer, vector<vector<int>> &res, int forbegin)
    {
        auto sum = std::accumulate(buffer.begin(), buffer.end(), 0);
        if (sum >= target)
        {
            if (sum == target)
            {
                res.push_back(buffer);
                return true;
            }
            else
                return false;
        }

        for (int k = forbegin; k < candidates.size(); k++)
        {
            buffer.push_back(candidates[k]);
            dfs(candidates, target, buffer, res, k);
            buffer.pop_back();
        }
        return false;
    };
};