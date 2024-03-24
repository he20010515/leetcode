/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-24 17:43:46
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <cstdint>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sol(vector<int> &nums)
    {
        uint16_t helper = 0;
        vector<vector<int>> res;
        const auto size = nums.size();
        do
        {
            vector<int> thissubset;
            for (int k = 0; k < size; k++)
            {
                if ((helper >> k & 1) == 1)
                    thissubset.push_back(nums[k]);
            }
            res.push_back(thissubset);
            helper++;

        } while (helper < (1 << size));

        return res;
    }
};