/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-06 14:48:38
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <__tuple_dir/tuple_element.h>
#include <cctype>
#include <cstddef>
#include <functional>
#include <string>
#include <tuple>
#include <unordered_map>
#include <utility>
using namespace std;



class Solution
{
public:
    unordered_map<tuple<int, int>,
                  bool,
                  MyTupleHash<1, int, int>>
        map = {};
    string str, pattern;
    bool sol(string s, string p)
    {
        /*
        ! '.' 匹配任意单个字符
        ! '*' 匹配**零个或多个前面的元素**
        */
        map.clear();
        this->str = s;
        this->pattern = p;
        return dp(0, 0);
    }
    bool dp(int i, int j) // 表示 p[j..] 是否匹配到 s[i..]
    {
        // base case 字符串或者正则有一个匹配完成, 考虑边界条件

        // debug watch 变量
        // auto cur_s = str.substr(i, str.size() - i);
        // auto cur_p = pattern.substr(j, pattern.size() - j);

        if (i == str.size())
        {
            if (j == pattern.size())
            {
                return true;
            }
            else
            {
                // 剩下的字符如果能匹配空串'', 那么剩下的表达式一定是偶数个字符
                if ((pattern.size() - j) % 2 == 1)
                {
                    return false;
                }
                else
                {
                    for (auto k = j; k < pattern.size(); k += 2)
                    {
                        if (pattern[k + 1] != '*')
                        {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
        else if (j == pattern.size())
        {
            if (i == str.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (map.contains(std::make_tuple(i, j)))
            return map[std::make_tuple(i, j)];
        // 否则进行匹配
        bool res;
        if (str[i] == pattern[j] or pattern[j] == '.')
        {
            if (j < pattern.size() and pattern[j + 1] == '*') // 通配符匹配0-无穷次;
            {
                // 匹配零次, 则表达式串跳过 "a*" 总计两个字符;
                // 匹配数次, 则字符串跳过一个字符继续考虑;
                res = dp(i, j + 2) or dp(i + 1, j);
            }
            else
            {
                // 常规匹配
                res = dp(i + 1, j + 1);
            }
        }
        else // 不匹配
        {
            if (j < pattern.size() and pattern[j + 1] == '*')
            { // 只能匹配通配符0次
                res = dp(i, j + 2);
            }
            else
            {
                // 无法匹配
                res = false;
            }
        }
        map[std::make_tuple(i, j)] = res;
        return res;
    }
};