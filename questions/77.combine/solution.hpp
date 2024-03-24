/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-24 17:36:41
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
    vector<vector<int>> sol(int n, int k)
    {
        vector<int> buffer;
        vector<vector<int>> res;
        dfs(1, buffer, res, n, k);
        return res;
    };
    void dfs(int begin_index, vector<int> &buffer, vector<vector<int>> &res, int n, int k)
    {
        if (buffer.size() == k)
        {
            res.push_back(buffer);
            return;
        }
        else
        {
            for (int i = begin_index; i <= n; i++)
            {
                buffer.push_back(i);
                dfs(i + 1, buffer, res, n, k);
                buffer.pop_back();
            }
        }
        return;
    }
};