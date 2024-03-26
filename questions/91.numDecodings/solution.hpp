/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 16:44:21
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <vector>
using namespace std;
class Solution
{
public:
    int sol(string s)
    {
        vector<int> memo(s.size() + 2, -1);
        return dfs(s, 0, memo);
    }
    int dfs(string &s, int matchindex, vector<int> &memo)
    {
        if (memo[matchindex] != -1)
            return memo[matchindex];

        if (matchindex == s.size()) // 到最后一个字符了
            return 1;

        int res = 0;
        // 匹配一个字符
        if (s[matchindex] <= '9' and s[matchindex] >= '1')
            res += dfs(s, matchindex + 1, memo);

        // 匹配两个字符
        if (matchindex < s.size() - 1 and // 至少还剩两个字符
            ((s[matchindex] == '1')       // 10,11-19;
             or (s[matchindex] == '2' and s[matchindex + 1] <= '6')))
            res += dfs(s, matchindex + 2, memo);
        return memo[matchindex] = res;
    }
};