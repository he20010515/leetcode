/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-27 13:33:26
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
    bool sol(string s1, string s2, string s3)
    {
        vector<int> path1, path2;
        return match(s1, s2, path1, path2, s3);
    }
    bool match(string &s1, string &s2, vector<int> &path1, vector<int> &path2, string &s3, int curlen = 0)
    {
        // exit
        if (curlen == s3.size())
            return true;
        //
        auto index1 = path1.size() > 0 ? path1[path1.size() - 1] : 0,
             index2 = path2.size() > 0 ? path2[path2.size() - 1] : 0;
        int step_l = 0, step_r = 0;
        while (curlen + step_l < s3.size() and s1[index1 + step_l] == s3[curlen + step_l])
            step_l++;
        while (curlen + step_r < s3.size() and s2[index2 + step_r] == s3[curlen + step_r])
            step_r++;
        bool match1 = false, match2 = false;

        if (step_l == 0 and step_r == 0)
            return false;

        if (step_l > 0)
        {
            for (int thisrange = step_l; step_l >= 1; step_l--)
            {
                path1.push_back(index1 + thisrange);
                match1 = match1 or match(s1, s2, path1, path2, s3, curlen + thisrange);
                path1.pop_back();
            }
        }

        if (step_r > 0)
        {
            for (int thisrange = step_r; step_r >= 1; step_r--)
            {
                path2.push_back(index2 + thisrange);
                match2 = match2 or match(s1, s2, path1, path2, s3, curlen + thisrange);
                path2.pop_back();
            }
        }

        return match1 or match2;
    }
};