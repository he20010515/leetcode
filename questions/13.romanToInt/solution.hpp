/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-07 11:42:18
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
static unordered_map<char, int> char2num = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};
static char tens[5] = "IXCM";
static char fives[4] = "VLD";
class Solution
{
public:
    int sol(string s)
    {
        auto res = 0;
        for (auto ch = s.begin(); ch != s.end(); ch++)
        {
            if (ch[0] == 'I' and ch[1] == 'V')
            {
                ch++;
                res += 4;
            }
            else if (ch[0] == 'I' and ch[1] == 'X')
            {
                ch++;
                res += 9;
            }
            else if (ch[0] == 'X' and ch[1] == 'L')
            {
                ch++;
                res += 40;
            }
            else if (ch[0] == 'X' and ch[1] == 'C')
            {
                ch++;
                res += 90;
            }
            else if (ch[0] == 'C' and ch[1] == 'D')
            {
                ch++;
                res += 400;
            }
            else if (ch[0] == 'C' and ch[1] == 'M')
            {
                ch++;
                res += 900;
            }
            else
            {
                res += char2num[*ch];
            }
        }
        return res;
    }
};