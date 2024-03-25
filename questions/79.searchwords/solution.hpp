/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 02:36:05
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <cstdint>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
private:
    int m, n;

public:
    bool sol(vector<vector<char>> &board, string &word)
    {
        this->m = board.size();
        this->n = board[0].size();
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j] == word[0])
                {
                    vector<pair<int, int>> path;
                    path.push_back({i, j});
                    if (dfs(board, i, j, word, path))
                        return true;
                }

        return false;
    }
    bool dfs(vector<vector<char>> &board, int i, int j, string &word, vector<pair<int, int>> &path, int begin = 0)
    {
        // assert board[i][j] == word[begin];
        if (begin == word.size() - 1)
            return true;
        // 如果order等于any, 四个方向都可以搜索, 如果order为up, 则不能向down方向搜索了;
        bool l = false, r = false, u = false, d = false;

        // // right
        // if (j < n - 1 and board[i][j + 1] == word[begin + 1] and
        //     find(path.begin(), path.end(), pair(i, j + 1)) == path.end())
        // {
        //     path.push_back(pair(i, j + 1));
        //     r = dfs(board, i, j + 1, word, path, begin + 1);
        //     path.pop_back();
        // }
        // // left
        // if (0 < j and board[i][j - 1] == word[begin + 1])
        //     l = dfs(board, i, j - 1, word, path, begin + 1);
        // // down
        // if (i < m - 1 and board[i + 1][j] == word[begin + 1])
        //     u = dfs(board, i + 1, j, word, path, begin + 1);
        // // up
        // if (0 < i and board[i - 1][j] == word[begin + 1])
        //     d = dfs(board, i - 1, j, word, path, begin + 1);

        // right
        if (j < n - 1 and board[i][j + 1] == word[begin + 1] and
            find(path.begin(), path.end(), pair(i, j + 1)) == path.end())
        {
            path.push_back(pair(i, j + 1));
            r = dfs(board, i, j + 1, word, path, begin + 1);
            path.pop_back();
        }

        // left
        if (0 < j and board[i][j - 1] == word[begin + 1] and
            find(path.begin(), path.end(), pair(i, j - 1)) == path.end())
        {
            path.push_back(pair(i, j - 1));
            l = dfs(board, i, j - 1, word, path, begin + 1);
            path.pop_back();
        }

        // down
        if (i < m - 1 and board[i + 1][j] == word[begin + 1] and
            find(path.begin(), path.end(), pair(i + 1, j)) == path.end())
        {
            path.push_back(pair(i + 1, j));
            u = dfs(board, i + 1, j, word, path, begin + 1);
            path.pop_back();
        }

        // up
        if (0 < i and board[i - 1][j] == word[begin + 1] and
            find(path.begin(), path.end(), pair(i - 1, j)) == path.end())
        {
            path.push_back(pair(i - 1, j));
            d = dfs(board, i - 1, j, word, path, begin + 1);
            path.pop_back();
        }

        return l or r or u or d;
    }
};