/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-13 21:17:37
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <ranges>
#include <string>
#include <string_view>
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

        auto words2id = unordered_map<string, int>();
        auto index = 0;
        auto tar = vector<int>();
        auto res = vector<int>();
        for (auto &word : words)
        {
            if (words2id.contains(word))
            {
                tar[words2id[word]]++;
                continue;
            }
            words2id.insert({word, index++});
            tar.push_back(1);
        }

        // slide window
        for (int index = 0; index < string_size - (word_nums * word_length) + 1; index++)
        {
            vector<int> cur(tar.size(), 0);
            for (int w = 0; w < word_nums; w++)
            {
                auto view = s.substr(index + w * word_length, word_length);
                if (words2id.contains(view))
                    cur[words2id[view]]++;

                else
                    break;
            }
            if (cur == tar)
                res.push_back(index);
        }
        return res;
    }
};