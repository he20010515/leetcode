/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-21 15:21:41
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <array>
#include <vector>
using namespace std;

inline array<int, 2> operator+(const array<int, 2> &a, const array<int, 2> &b)
{
    array<int, 2> add;
    add[0] = a[0] + b[0];
    add[1] = a[1] + b[1];
    return add;
}

class Solution
{
public:
    vector<int> sol(vector<vector<int>> matrix)
    {
        vector<int> res(matrix.size() * matrix[0].size());
        array<int, 2> pos = {0, 0};
        const array<int, 2> l = {0, -1},
                            r = {0, 1},
                            u = {-1, 0},
                            d = {1, 0};
        const int row = 0, col = 1;

        array<int, 2> order = matrix[0].size() > 1 ? r : d;
        int step = 0;
        int ub = 0, db = matrix.size() - 1, lb = 0, rb = matrix[0].size() - 1;
        res[step] = matrix[pos[row]][pos[col]];
        while (true)
        {
            step++;
            pos = pos + order;
            res[step] = matrix[pos[row]][pos[col]];
            if (step == res.size() - 1)
                break;

            if (pos[col] == rb and order == r)
            {
                order = d;
                ub++;
            }
            else if (pos[row] == db and order == d)
            {
                order = l;
                rb--;
            }
            else if (pos[col] == lb and order == l)
            {
                db--;
                order = u;
            }
            else if (pos[row] == ub and order == u)
            {
                lb++;
                order = r;
            };
        }
        return res;
    }
};