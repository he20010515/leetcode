/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-20 21:16:46
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <_types/_uint8_t.h>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct wordFinger_t
{
    uint8_t counts[26];
    bool operator==(const struct wordFinger_t &other) const
    {
        for (int i = 0; i < 26; i++)
            if (this->counts[i] != other.counts[i])
                return false;
        return true;
    }
};

class WordFinger_Hash_t
{
public:
    inline size_t operator()(const wordFinger_t &p) const
    {
        const size_t prime = 31;
        size_t seed = 1;
        for (int i = 0; i < 26; i++)
            seed ^= p.counts[i] * seed + prime;
        return seed;
    }
};

class Solution
{
public:
    vector<vector<string>> sol(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<struct wordFinger_t, vector<string>, WordFinger_Hash_t> mapper;
        for (auto &word : strs)
        {
            auto ret = count(word);
            auto f = mapper.find(ret);
            if (f == mapper.end())
            {
                mapper[ret] = vector<string>();
            }
            mapper[ret].push_back(word);
        }

        for (auto &[f, v] : mapper)
            res.push_back(std::move(v));

        return res;
    }
    struct wordFinger_t count(string &word)
    {
        struct wordFinger_t ret = {};
        for (auto &c : word)
            ret.counts[c - 'a']++;
        return ret;
    }
};