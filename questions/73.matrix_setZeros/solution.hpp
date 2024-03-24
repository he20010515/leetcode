/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-24 15:51:37
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
        const auto m = matrix.size(), n = matrix[0].size();
        bool flag_1st_row = false, flag_1st_col = false;
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
            {
                flag_1st_col = true;
                break;
            }

        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
            {
                flag_1st_row = true;
                break;
            }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for (int i = 1; i < m; i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
        for (int j = 1; j < n; j++)
            if (matrix[0][j] == 0)
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
        if (flag_1st_row)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (flag_1st_col)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        return matrix;
    }
};