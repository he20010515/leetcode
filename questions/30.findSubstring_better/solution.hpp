/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-13 22:16:20
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <ranges>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utility>
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
        const auto window_size = word_nums * word_length;
        auto target_word_count = unordered_map<string, int>();
        for (auto word : words)
            target_word_count[word]++;
        auto res = vector<int>();

        for (int offset = 0; offset < word_length; offset++)
        {
            auto differ = unordered_map<string, int>(target_word_count);
            // init curmap in first step window;
            auto w_index = 0;
            for (; w_index < word_nums; w_index++)
            {
                if (differ.contains(s.substr(offset + w_index * word_length, word_length)))
                    differ[s.substr(offset + w_index * word_length, word_length)]--;
            }
            // go on
            w_index = 0;
            while (offset + ((w_index + 1) * word_length) + window_size < string_size + 1)
            {
                if (std::all_of(differ.begin(), differ.end(), [](std::pair<string, int> p)
                                { return p.second == 0; }))
                    res.push_back(offset + w_index * word_length);
                auto left = s.substr(offset + w_index * word_length, word_length);
                auto right = s.substr(offset + w_index * word_length + window_size, word_length);
                if (differ.contains(left))
                    differ[left]++;
                if (differ.contains(right))
                    differ[right]--;
                w_index++;
            }
            if (std::all_of(differ.begin(), differ.end(), [](std::pair<string, int> p)
                            { return p.second == 0; }))
                res.push_back(offset + w_index * word_length);
        }
        return res;
    }
};