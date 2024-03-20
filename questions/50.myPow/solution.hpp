/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-20 21:42:08
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
using namespace std;
class Solution
{
public:
    double sol(double x, int n)
    {
        if (n == 0)
            return 1.0;

        bool isnagtive = n < 0;
        uint absn = abs(n);
        double temp = x;
        double res = 1.0;
        while (absn != 0)
        {
            if ((absn & 1) == 1) // 如果最后一位是1, 说明要加上去当前数
                res *= temp;
            temp = temp * temp;
            absn >>= 1;
        }
        return isnagtive ? 1 / res : res;
    };
};