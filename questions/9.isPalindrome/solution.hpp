/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-06 09:55:53
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <limits>
using namespace std;
class Solution
{
public:
    bool sol(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int re_a = 0, temp = x;
        while (temp != 0)
        {
            if (re_a > std::numeric_limits<int>::max() / 10)
                return false;

            re_a = re_a * 10 + temp % 10;
            temp /= 10;
        }
        if (re_a == x)
            return true;
        else
            return false;
    }
};