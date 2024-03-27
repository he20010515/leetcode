/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-27 10:00:32
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cmath>
#include <map>
#include <utility>
using namespace std;
class Solution
{
public:
    static map<pair<int, int>, int> memo;
    int sol(int n)
    {
        if (memo.contains({1, n}))
            return memo[{1, n}];
        else
            return dp(1, n);
    }
    int dp(int l, int r)
    {
        if (memo.contains({l, r}))
            return memo[{l, r}];

        if (l > r)
            return 1;
        int res = 0;
        for (int i = l; i <= r; i++)
        {
            auto leftTrees = dp(l, i - 1);
            auto rightTrees = dp(i + 1, r);
            res += leftTrees * rightTrees;
        }
        return memo[{l, r}] = res;
    }
};
map<pair<int, int>, int> Solution::memo = {};