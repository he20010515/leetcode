/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-15 12:39:03
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool sol(vector<vector<char>> &board)
    {
        // row check;
        auto check = unordered_map<char, bool>();
        for (int row = 0; row < 9; row++)
        {
            check.clear();
            for (int column = 0; column < 9; column++)
            {
                auto c = board[row][column];
                if (c == '.')
                    continue;

                if (check.contains(c))
                    return false;
                else
                    check[c] = true;
            }
        }
        // column check;
        for (int column = 0; column < 9; column++)
        {
            check.clear();
            for (int row = 0; row < 9; row++)
            {
                auto c = board[row][column];
                if (c == '.')
                    continue;

                if (check.contains(c))
                    return false;
                else
                    check[c] = true;
            }
        }

        // block check;
        for (int column = 0; column < 3; column++)
        {
            for (int row = 0; row < 3; row++)
            {
                check.clear();
                auto check = unordered_map<char, bool>();
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        auto c = board[3 * row + i][3 * column + j];
                        if (c == '.')
                            continue;

                        if (check.contains(c))
                            return false;
                        else
                            check[c] = true;
                    }
                }
            }
        }
        return true;
    }
};