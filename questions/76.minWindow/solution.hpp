/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-24 17:26:28
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <limits>
using namespace std;
class Solution
{
public:
    string sol(string s, string t)
    {
        if (t.size() > s.size())
            return "";
        int counter['z' - 'A' + 1] = {};
        int targetc['z' - 'A' + 1] = {};
        for (char ch : t)
            targetc[ch - 'A']++;
        auto contain = [](int c['z' - 'A'], int target['z' - 'A'])
        {
            for (int i = 0; i < 'z' - 'A' + 1; i++)
                if (target[i] > 0 and c[i] < target[i])
                {
                    return false;
                }
            return true;
        };

        const auto string_size = s.size();
        auto slow = 0, fast = 0; // 左闭右开
        auto target_subbegin = 0;
        auto min_length = numeric_limits<int>::max();

        while (slow < string_size and fast < string_size)
        {
            counter[s[fast++] - 'A']++;    // fast新进字符计数;
            if (contain(counter, targetc)) // 判断是否包含
            {
                // 如果包含了, 慢指针前进,直到不包含
                while (slow < fast and contain(counter, targetc))
                    counter[s[(slow++)] - 'A']--; // 慢指针前进, 计数器对应字母减一
                // 找到了一个局部最小的子串 [slow-1,fast)
                if (fast - slow + 1 < min_length)
                {
                    min_length = fast - slow + 1;
                    target_subbegin = slow - 1;
                }
            }
        }
        if (min_length == numeric_limits<int>::max())
            return "";

        return s.substr(target_subbegin, min_length);
    }
};