/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-16 18:28:15
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <atomic>
#include <ostream>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<char>> sol(vector<vector<char>> &board)
    {
        row_status = vector<vector<bool>>(10, vector(10, false));
        col_status = vector<vector<bool>>(10, vector(10, false));
        rom_status = vector<vector<vector<bool>>>(3, vector(3, vector(10, false)));

        for (int row = 0; row < 9; row++)
            for (int col = 0; col < 9; col++)
                if (board[row][col] != '.')
                {
                    row_status[row][board[row][col] - '0'] = true;
                    col_status[col][board[row][col] - '0'] = true;
                    auto rom_row = row / 3, rom_col = col / 3;
                    rom_status[rom_row][rom_col][board[row][col] - '0'] = true;
                }
        solve(0, 0, board);
        return board;
    };
    bool solve(int i, int j, vector<vector<char>> &board)
    {
        if (i == 9)
            return true;
        if (board[i][j] != '.')
            return solve(j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1, board);
        else
        {
            // 寻找可以填的数
            vector<char> avaliable_chars;
            auto rom_row = i / 3, rom_col = j / 3;
            for (int num = 1; num <= 9; num++)
            {
                // xxx_status_[i][num] 表示第i行中第num个数是否存在;
                if (row_status[i][num] or col_status[j][num] or rom_status[rom_row][rom_col][num])
                    continue;
                avaliable_chars.push_back(static_cast<char>('0' + num));
            }
            // 尝试填入数
            std::cout << i << "\t" << j << "\t" << avaliable_chars << endl;
            for (auto c : avaliable_chars)
            {
                board[i][j] = c;
                row_status[i][c - '0'] = true;
                col_status[j][c - '0'] = true;
                rom_status[i / 3][j / 3][c - '0'] = true;

                if (solve(j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1, board))
                    return true;

                board[i][j] = '.';
                row_status[i][c - '0'] = false;
                col_status[j][c - '0'] = false;
                rom_status[i / 3][j / 3][c - '0'] = false;
            }
            // 没有可以插入的数, 回溯
            return false;
        }
    };

private:
    vector<vector<bool>> row_status;
    vector<vector<bool>> col_status;
    vector<vector<vector<bool>>> rom_status;
};