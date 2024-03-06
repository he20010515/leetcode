/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-05 21:10:41
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
// #include <string>
// #include <vector>

using namespace std;
class Solution
{
public:
    string sol(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        auto layers = vector<int>(s.length(), 0);
        auto current_layer = 1, step = 1;
        for (size_t i = 0; i < s.length(); i++)
        {
            layers[i] = current_layer;
            current_layer += step;
            if ((current_layer == 1 and step == -1) or
                (current_layer == numRows and step == 1))
                step = -step;
        };
        auto res = vector<char>(s.length(), ' ');
        auto p = res.begin();
        for (auto cr = 1; cr <= numRows; cr++)
        {
            for (size_t i = 0; i < s.length(); i++)
            {
                if (layers[i] == cr)
                    *p++ = s[i];
            }
        }
        res.push_back('\0');
        return string(res.data());
    }
};