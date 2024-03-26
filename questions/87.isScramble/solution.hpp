/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 16:19:59
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cassert>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    unordered_map<string, bool> memo;
    bool sol(string s1, string s2)
    {
        // 如果s1,s2;
        // 一定存在一个分割点, 这个分割点s1左右两端和s2左右两端的字母数量 严格相同或者交错相同;
        return dp(s1, s2);
    }
    bool dp(string s1, string s2)
    {
        const string key = s1 + "-" + s2;
        if (this->memo.contains(key))
            return memo[key];

        const auto s_size = s1.size();
        string s1left, s1right, s2left, s2right;
        bool res = false;
        // s1.size() == s2.size();
        if (s1.size() == 1)
            return s1[0] == s2[0];
        for (int i = 1; i < s1.size(); i++)
        {
            // 有交换的情况
            s1left = s1.substr(0, i), s1right = s1.substr(i, s_size - i);
            s2left = s2.substr(0, s_size - i), s2right = s2.substr(s_size - i, i);
            res = res or (dp(s1left, s2right) and dp(s1right, s2left));
            // 无交换的情况
            s1left = s1.substr(0, i), s1right = s1.substr(i, s_size - i);
            s2left = s2.substr(0, i), s2right = s2.substr(i, s_size - i);
            res = res or (dp(s1left, s2left) and dp(s1right, s2right));
        };
        return memo[key] = res;
    }
};