/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-04 12:12:44
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    double sol(vector<int> &nums1, vector<int> &nums2)
    {
        auto total = nums1.size() + nums2.size();
        vector<int> tar(total, 0);
        size_t l = 0, r = 0;
        for (size_t index = 0; index < total; index++)
        {

            if (l == nums1.size() or r == nums2.size())
            {
                if (l == nums1.size())
                {
                    tar[index] = nums2[r];
                    r++;
                }
                else
                {
                    // 拿左边的
                    tar[index] = nums1[l];
                    l++;
                }
            }
            else
            {
                if (nums1[l] < nums2[r])
                {
                    // 拿左边的
                    tar[index] = nums1[l];
                    l++;
                }
                else
                {
                    // 拿右边的
                    tar[index] = nums2[r];
                    r++;
                }
            }
        }
        std::cout << tar << std::endl;
        if (total % 2 == 0)
            return 0.5 *
                   (tar[total / 2] + tar[total / 2 - 1]);
        else
            return tar[(total - 1) / 2];
    }
};