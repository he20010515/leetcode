/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-03 13:55:05
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> sol(vector<int> &nums, int target)
    {
        auto mappper = std::unordered_map<int, int>();
        int index = 0;
        vector<int> res(2, -1);
        for (auto num : nums)
        {
            if (mappper.contains(target - num))
            {
                auto rindex = mappper[target - num];
                res[0] = rindex;
                res[1] = index;
                return res;
            }
            mappper[num] = index;
            index++;
        }
        return res;
    }
};