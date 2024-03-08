/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-08 20:40:48
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sol(vector<int> &nums)
    {
        auto res_buffer = vector<vector<int>>();
        auto res = unordered_set<tuple<int, int, int>, MyTupleHash<2, int, int, int>>();
        auto sortNumbers = [](int a, int b, int c)
        {
            if (a > b)
                std::swap(a, b);
            if (a > c)
                std::swap(a, c);
            if (b > c)
                std::swap(b, c);
            return make_tuple(a, b, c);
        };
        int x, y, z, z_index;
        for (int x_index = 0; x_index < nums.size(); x_index++)
        {
            auto map = std::unordered_map<int, int>();
            // 两数之和问题, 目标数是 -x;
            for (int y_index = 0; y_index < nums.size(); y_index++)
            {
                if (y_index == x_index)
                    continue;
                x = nums[x_index];
                y = nums[y_index];
                z = -x - y;
                if (map.contains(z))
                {
                    z_index = map[z];
                    if (z_index == x_index or z_index == y_index)
                    {
                        // do nothing
                    }
                    else
                    {

                        auto [tx, ty, tz] = sortNumbers(x, y, z);
                        res.insert(make_tuple(tx, ty, tz));
                    }
                }
                map[y] = y_index;
            }
        }

        int temp[3] = {};

        for (const auto &[a, b, c] : res)
        {
            temp[0] = a;
            temp[1] = b;
            temp[2] = c;
            res_buffer.push_back(vector<int>(temp, temp + 3));
        }

        return res_buffer;
    }
};