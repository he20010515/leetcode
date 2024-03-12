/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-11 00:21:13
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sol(string s, vector<string> &words)
    {
        const auto word_length = words[0].length();
        const auto word_nums = words.size();
        const auto string_size = s.length();

        const auto offsetnum = string_size % word_length == 0 ? word_length : string_size % word_length;
        const auto buffer_length = offsetnum == word_length ? string_size / word_nums : string_size / word_nums + 1;
        auto map = unordered_map<string, int>(offsetnum);
        auto buffer = vector<vector<int>>(offsetnum, vector<int>(buffer_length, -1));
        auto counter = vector<int>(word_nums);
        auto t_counter = vector<int>(word_nums);

        for (int index = 1; index <= word_nums;)
            map[words[index]] = index; // 重复直接覆盖 ["a":1, "b":2,"c":4]

        return {};
    }
};