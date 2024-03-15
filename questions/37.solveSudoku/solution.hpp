/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-15 21:53:25
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <atomic>
#include <set>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using MemoType = vector<vector<unordered_set<char>>>;
class Solution
{
public:
    const unordered_set<char> charset = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    vector<vector<char>> sol(vector<vector<char>> &board)
    {
        auto memo = MemoType(9, vector<unordered_set<char>>(9, unordered_set<char>()));
        while (not isfinish(board))
        {
            updatememo(board, memo);
            updateboard(board, memo);
            std::cout << board << std::endl;
        }
        return board;
    };
    void updatememo(const vector<vector<char>> &board, MemoType &memo)
    {
        // 更新笔记
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                memo[row][col].clear();
                if (board[row][col] == '.')
                {
                    auto cs = unordered_set<char>(charset);
                    // 判断行还剩什么
                    for (int i = 0; i < 9; i++)
                        if (board[row][i] != '.')
                            cs.erase(board[row][i]);
                    // 判断列还剩什么
                    for (int i = 0; i < 9; i++)
                        if (board[i][col] != '.')
                            cs.erase(board[i][col]);
                    // 判断宫内还剩什么
                    auto room_row = row / 3, room_col = col / 3;
                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            if (board[3 * room_row + i][3 * room_col + j] != '.')
                                cs.erase(board[3 * room_row + i][3 * room_col + j]);
                    memo[row][col] = cs;
                }
                else
                    memo[row][col].insert(board[row][col]);
            }
        }
    };
    void updateboard(vector<vector<char>> &board, const MemoType &memo)
    {
        for (int row = 0; row < 9; row++)
            for (int col = 0; col < 9; col++)
                if (board[row][col] == '.' and memo[row][col].size() == 1)
                    board[row][col] = *memo[row][col].begin();
        // 寻找独特元素

        // 按行搜索
        for (int row = 0; row < 9; row++)
        {
            auto counter = unordered_map<char, tuple<int, int, int>>();
            for (int col = 0; col < 9; col++)
                for (auto ele : memo[row][col])
                {
                    get<0>(counter[ele])++;
                    get<1>(counter[ele]) = row;
                    get<2>(counter[ele]) = col;
                }
            for (auto [c, t] : counter)
            {
                auto [nums, row, col] = t;
                if (nums != 1)
                    continue;
                board[row][col] = c;
            }
        }

        // 按列搜索
        for (int col = 0; col < 9; col++)
        {
            auto counter = unordered_map<char, tuple<int, int, int>>();
            for (int row = 0; row < 9; row++)
                for (auto ele : memo[row][col])
                {
                    get<0>(counter[ele])++;
                    get<1>(counter[ele]) = row;
                    get<2>(counter[ele]) = col;
                }
            for (auto [c, t] : counter)
            {
                auto [nums, row, col] = t;
                if (nums != 1)
                    continue;
                board[row][col] = c;
            }
        }

        // 按宫搜索
        for (int room_row = 0; room_row < 3; room_row++)
            for (int room_col = 0; room_col < 3; room_col++)
            {
                auto counter = unordered_map<char, tuple<int, int, int>>();
                for (int i; i < 3; i++)
                    for (int j; j < 3; j++)
                        for (auto ele : memo[room_row * 3 + i][room_col * 3 + j])
                        {
                            get<0>(counter[ele])++;
                            get<1>(counter[ele]) = room_row * 3 + i;
                            get<2>(counter[ele]) = room_col * 3 + j;
                        }
                for (auto [c, t] : counter)
                {
                    auto [nums, row, col] = t;
                    if (nums != 1)
                        continue;
                    board[row][col] = c;
                }
            }
    }
    bool isfinish(const vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    return false;
                }
            }
        }
        return true;
    }
};