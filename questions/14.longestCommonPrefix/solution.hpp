/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-07 11:57:48
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string sol(vector<string> &strs)
    {
        auto p = 0;
        auto temp_char = '\0';
        while (true)
        {
            temp_char = strs[0].c_str()[p];
            for (auto &&str : strs)
            {
                if (temp_char != str[p] or temp_char == '\0')
                {
                    return str.substr(0, p);
                }
            }
            p++;
        }
    }
};