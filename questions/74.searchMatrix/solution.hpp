/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-24 16:15:44
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cstddef>
#include <vector>
using namespace std;
class Solution
{
public:
    bool sol(vector<vector<int>> &matrix, int target)
    {
        const auto m = matrix.size(), n = matrix[0].size();
        if (m == n and m == 1)
            return matrix[0][0] == target;

        auto loc = [&](int pos)
        {
            auto i = pos / n, j = pos % n;
            return matrix[i][j];
        };
        if (m * n == 2)
            return loc(0) == target or loc(1) == target;

        size_t l = 0, r = m * n - 1, mid;
        while (l + 1 != r)
        {
            if (loc(l) == target or loc(r) == target)
                return true;
            mid = (l + r) >> 1;
            if (loc(mid) > target)
                r = mid;
            else if (loc(mid) < target)
                l = mid;
            else
                return true;
        }
        return false;
    };
};