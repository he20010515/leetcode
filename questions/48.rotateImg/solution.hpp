/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-20 20:04:46
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
    vector<vector<int>> sol(vector<vector<int>> &matrix)
    {
        auto n = matrix.size();
        if (n % 2 == 0)
        {
            for (int i = 0; i < n / 2; i++)
                for (int j = 0; j < n / 2; j++)
                    rotate(matrix[i][j], matrix[j][n - i - 1],
                           matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]);
        }
        else
        {
            auto centerline = n / 2;
            for (int i = 0; i < centerline; i++)
                for (int j = 0; j < centerline; j++)
                    rotate(matrix[i][j], matrix[j][n - i - 1],
                           matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]);
            for (int r = 0; r < centerline; r++)
                rotate(matrix[centerline][r], matrix[r][centerline],
                       matrix[centerline][n - r - 1], matrix[n - r - 1][centerline]);
        };
        return matrix;
    }
    inline void rotate(int &a, int &b, int &c, int &d)
    {
        int temp = d;
        d = c;
        c = b;
        b = a;
        a = temp;
        return;
    }
};