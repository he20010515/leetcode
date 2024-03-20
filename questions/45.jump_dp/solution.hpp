/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-19 23:17:57
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <limits>
#include <vector>
using namespace std;
class Solution
{
private:
    int N;
    int curbestsize;

public:
    int sol(vector<int> &nums)
    {
        this->N = nums.size();
        this->curbestsize = std::numeric_limits<int>::max();
        vector<int> path;
        path.push_back(0);
        dp(nums, path);
        return this->curbestsize;
    }
    bool dp(vector<int> &nums, vector<int> &path)
    {
        auto curpos = path[path.size() - 1];
        if (curpos == N - 1)
            curbestsize = min(static_cast<int>(path.size() - 1), curbestsize);
        else if (nums[curpos] == 0)
            return false;
        else if (path.size() > curbestsize)
            return false;

        for (int range = nums[curpos]; range >= 1; range--)
        {
            if (curpos + range > N - 1)
                continue;
            path.push_back(curpos + range);
            dp(nums, path);
            path.pop_back();
        }
        return false;
    }
};