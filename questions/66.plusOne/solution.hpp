/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-23 16:31:56
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sol(vector<int> digits)
    {
        auto p = digits.rbegin();
        for (; p != digits.rend(); p++)
        {
            if (*p == 9)
            {
                *p = 0;
                continue;
            }
            (*p)++;
            break;
        }
        if (p == digits.rend())
        {
            auto res = vector<int>(digits.size() + 1, 0);
            res[0] = 1;
            return std::move(res);
        }

        return digits;
    }
};