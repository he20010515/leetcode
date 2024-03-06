/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-04 10:22:23
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-04 11:10:21
 * @FilePath: /leetcode/questions/3.lengthOfLongestSubstring_window/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include "string"
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int sol(string s)
    {
        if (s.length() == 0)
            return 0;

        auto cur_windows_char_set = unordered_set<char>();
        int res = 0, left = 0;
        for (int right = 0; right < s.length(); right++)
        {
            while (cur_windows_char_set.contains(s[right]))
            {
                cur_windows_char_set.erase(s[left]);
                left++;
            }
            res = (right - left + 1) > res ? (right - left + 1) : res;
            cur_windows_char_set.insert(s[right]);
        }
        return res;
    }
};