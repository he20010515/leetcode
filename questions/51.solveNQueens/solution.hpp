/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-17 21:46:41
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
    using mapT = vector<string>;
    using resT = vector<vector<string>>;
    using staT = vector<bool>;

private:
    int n;
    vector<bool> sums;
    vector<bool> diff;
    vector<bool> cols;
    mapT map;

public:
    resT sol(int n)
    {
        map = mapT(n, string(n, '.'));
        auto res = resT();
        auto path = vector<int>();

        this->sums = vector<bool>(2 * n - 1, false); // 坐标和的范围是 [0,2n-2]
        this->diff = vector<bool>(2 * n - 1, false); // 坐标差的范围是 [-(n-1),n-1]
        this->cols = vector<bool>(n, false);
        this->n = n;
        dfs(res, path);
        return res;
    };
    bool dfs(resT &res, vector<int> &path, int i = 0)
    {
        if (i == this->n)
        {
            for (int si = 0; si < n; si++)
                map[si][path[si]] = 'Q';
            res.push_back(map);
            for (int si = 0; si < n; si++)
                map[si][path[si]] = '.';
            return true;
        };

        for (int j = 0; j < this->n; j++)
        {

            // 通过和以及差判断斜线上是否重复
            // 通过纵坐标判断列是否重复 ;
            if (sums[i + j] or diff[n - 1 + i - j] or cols[j])
                continue;

            sums[i + j] = true;
            diff[n - 1 + i - j] = true;
            cols[j] = true;
            path.push_back(j);

            dfs(res, path, i + 1);

            path.pop_back();
            sums[i + j] = false;
            diff[n - 1 + i - j] = false;
            cols[j] = false;
        }
        return true;
    };
};