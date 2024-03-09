/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 14:28:10
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cstddef>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
using namespace std;
static unordered_map<char, string> map{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

class Solution
{

public:
    vector<string> sol(string dights)
    {
        if (dights == "")
            return {};

        size_t string_num = 1;

        auto res = vector<string>();
        string buffer;
        back_track(res, dights, 0, buffer);
        return res;
    };

    void back_track(vector<string> &res, const string &dights, int index, string &buffer)
    {
        if (index == dights.length())
        {
            res.push_back(buffer);
            return;
        }
        else
        {
            char dight = dights[index];
            for (const auto &ch : map[dight])
            {
                buffer.push_back(ch);
                back_track(res, dights, index + 1, buffer);
                buffer.pop_back();
            }
        }
    }
};