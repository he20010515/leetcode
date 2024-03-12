/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-12 14:59:13
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <functional>
#include <string>
#include <string_view>
using namespace std;
class Solution
{
public:
    int sol(string haystack, string needle)
    {
        const auto string_size = haystack.size();
        const auto needle_size = needle.size();
        if (needle_size > string_size)
            return -1;
        if (needle_size == string_size)
        {
            if (haystack == needle)
                return 0;
            else
                return -1;
        };

        for (int index = 0; index < string_size - needle_size + 1; index++)

            if (haystack.substr(index, needle_size) == needle)
                return index;

        return -1;
    }
};