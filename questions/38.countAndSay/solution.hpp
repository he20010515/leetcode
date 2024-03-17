/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-17 09:13:34
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <string>
using namespace std;
class Solution
{
public:
    string sol(int a)
    {
        return getn(a);
    };

    string getn(int n)
    {
        if (n <= 1)
            return "1";
        return des(getn(n - 1));
    };

    string des(const string &nums)
    {
        int counter = 0, pointer = 0;
        char temp = '\0';
        string res = "";
        while (pointer < nums.size())
        {
            counter = 1;
            temp = nums[pointer];
            while (nums[pointer + 1] == temp and pointer + 1 < nums.size())
                pointer++, counter++;
            res += int2string(counter) + temp;
            pointer++;
        }
        return res;
    };
    string int2string(int x)
    {
        int t;
        string res;
        while (x != 0)
        {
            t = x % 10;
            x /= 10;
            res.push_back(t + '0');
        };
        return string(res.rbegin(), res.rend());
    };
};