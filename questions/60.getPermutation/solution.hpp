/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-21 18:04:14
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <sys/types.h>
#include <vector>
using namespace std;
class Solution
{
public:
    string sol(int n, int k)
    {
        if (n == 1)
            return "1";
        k--; // 将以1为起点换为以0为起点;
        // 将k转换为递增进制数;
        array<int, 9> upper = {};
        vector<char> buf = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string res;
        for (int base = 2; base <= n; base++)
        {
            upper[base - 1] = k % base;
            k /= base;
        };
        for (int i = n - 1; i >= 0; i--)
        {
            res.push_back(buf[upper[i]]);
            buf.erase(find(buf.begin(), buf.end(), buf[upper[i]]));
        }
        return res;
    }
};