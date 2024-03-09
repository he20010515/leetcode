/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 16:18:51
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
    bool sol(string s)
    {
        auto stack = vector<char>();
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '[':
            case '{':
                stack.push_back(c);
                break;
            case ')':
            case ']':
            case '}':
                if (stack.empty())
                    return false;
                auto pop = stack[stack.size() - 1];
                stack.pop_back();
                if (pop + 1 == c or pop + 2 == c)
                {
                }
                else
                {
                    return false;
                }
            }
        };

        return stack.empty();
    }
};