/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-03 16:29:46
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-04 11:44:49
 * @FilePath: /leetcode/questions/3.lengthOfLongestSubstring_bad/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int sol(string s)
    {
        if (s.length() == 0)
            return 0;
        if (s.length() == 1)
            return 1;
        auto set = unordered_set<char>();
        int res = 0;
        for (auto i = s.begin(); i != s.end(); i++)
        {
            for (auto j = i + 1; j != s.end() + 1; j++)
            {
                set.clear();
                int len = 0;
                for (auto k = i; k != j; k++)
                {
                    if (set.contains(*k))
                    {
                        len = 0;
                        break;
                    }
                    len++;
                    set.insert(*k);
                }
                res = len > res ? len : res;
            }
        }
        return res;
    }
};