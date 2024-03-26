/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 16:26:34
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
    vector<vector<int>> sol(vector<int> &nums)
    {

        vector<vector<int>> res;
        vector<int> path;
        dfs(path, nums, res, 0);
        return res;
    }
    void dfs(vector<int> &path, vector<int> &nums,
             vector<vector<int>> &res, int beginnum)
    {
        res.push_back(path);
        if (beginnum == nums.size())
            return;

        for (int i = beginnum; i < nums.size(); i++)
        {
            if (i > beginnum and nums[i - 1] == nums[i])
                continue;
            path.push_back(nums[i]);
            dfs(path, nums, res, i + 1);
            path.pop_back();
        }
        return;
    }
};

/*
    void
  1      2    3
2   3    3

     void
    1      2       2
  2   2    2
  2   2

*/