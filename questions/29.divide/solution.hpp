/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-13 10:57:28
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cstdlib>
#include <limits>
#include <type_traits>
using namespace std;
class Solution
{
public:
    int sol(int dividend, int divisor)
    {
        if (dividend == -2147483648 and divisor == -1)
            return 2147483647;
        uint32_t a = labs(dividend);
        const uint32_t b = labs(divisor);
        uint32_t res = 0;
        int sign = (dividend > 0) xor (divisor > 0) ? -1 : 1;
        if (a == b)
            return sign;
        for (int k = 1; k <= 32; k++)
        {
            if (a >> (32 - k) >= b)
            {
                a -= (b << (32 - k));
                res += (1 << (32 - k));
            }
        }
        return sign == 1 ? res : -res;
    }
};