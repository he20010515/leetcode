/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-06 20:03:41
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
    string sol(int a)
    {
        vector<char> buffer;
        char index = 0;
        while (a != 0)
        {
            auto r = a % 10;
            a = a / 10;
            switch (r)
            {
            case 4:
                buffer.push_back(fives[index]);
                buffer.push_back(tens[index]);
                break;
            case 9:
                buffer.push_back(tens[index + 1]);
                buffer.push_back(tens[index]);
                break;
            case 0:
            case 1:
            case 2:
            case 3:
                for (int i = 0; i < r; i++)
                    buffer.push_back(tens[index]);
                break;
            case 5:
            case 6:
            case 7:
            case 8:
                for (int i = 0; i < r - 5; i++)
                    buffer.push_back(tens[index]);
                buffer.push_back(fives[index]);
            }
            index += 1;
        };
        return string(buffer.rbegin(), buffer.rend());
    }
};