/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-05 22:42:25
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include "inttypes.h"
#include <cmath>
using namespace std;
class Solution
{
public:
    int sol(int x)
    {
        const int32_t base = 10,
                      maxlen = 10; // 32位有符号整数在十进制下最多10位+符号位
        const int32_t tens[maxlen] = {
            1,
            10,
            100,
            1000,
            10000,
            100000,
            1000000,
            10000000,
            100000000,
            1000000000,
        };
        if (x == 0 or x == std::numeric_limits<int>::min())
            return 0;

        int32_t num = x > 0 ? x : -x;
        int32_t sign = x > 0 ? 1 : -1;
        char units[maxlen] = {}, p = 0;

        while (num != 0)
        {
            units[p++] = num % base;
            num /= base;
        }
        int32_t res = 0, buffer = 0;
        void *pointer = &buffer;
        for (uint32_t i = 0; i < p; i++)
        {
            if (units[i] > std::numeric_limits<int32_t>::max() / tens[p - i - 1])
                return 0;
            buffer = units[i] * tens[p - i - 1];
            if ((((buffer - res) >> 1) + res) >
                (std::numeric_limits<int32_t>::max() >> 1))
                return 0;
            res += buffer;
        }

        return sign * res;
    };
};