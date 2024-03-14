/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-14 16:40:45
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <atomic>
#include <deque>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
const static char L = '(', R = ')';
const static int unknown = -1;
const static int illegal = -2;

class Solution
{
public:
    int sol(string s)
    {
        if (s.length() <= 1)
            return 0;

        auto memo = vector<vector<int>>(s.size(), vector<int>(s.size(), unknown));
        int res = 0;
        for (int Len = 2; Len <= s.length(); Len += 2)
        {
            for (int left = 0; left < s.length() - Len + 1; left++)
            {
                auto right = left + Len - 1;
                if (Len == 2) // 如果长度为2, 那么只能为();
                {
                    if (s[left] == L and s[right] == R)
                        memo[left][right] = 2;
                }
                else // 分割和外包
                {
                    if (s[left] == L and s[right] == R and memo[left + 1][right - 1] > 0)
                        memo[left][right] = right - left + 1;
                    else
                    {
                        // left left+1 left+2 ... mid, mid+1, ..., right-1, right;
                        for (int mid = left + 1; mid < right; mid += 2)
                        {
                            if (memo[left][mid] > 0 and memo[mid + 1][right] > 0)
                            {
                                memo[left][right] = right - left + 1;
                                break;
                            }
                        };
                    }
                };
                if (memo[left][right] == unknown)
                    memo[left][right] = illegal;
                else
                {
                    res = memo[left][right] > res ? memo[left][right] : res;
                };
            }
        };
        return res;
    }
};