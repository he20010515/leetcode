/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-19 16:53:21
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <string>
#include <sys/types.h>
#include <vector>
using namespace std;
class Solution
{
public:
    string sol(string num1, string num2)
    {
        const int M = num1.size(), N = num2.size();
        if (num1[0] == '0' or num2[0] == '0')
            return "0";
        auto paper = vector<vector<uint>>(M, vector<uint>(N));
        for (int m = 0; m < M; m++)
            for (int n = 0; n < N; n++)
                paper[m][n] = (num1[m] - '0') * (num2[n] - '0');
        int upper = 0;
        int pos = M + N - 2;
        int posSum = 0;
        string res = "";

        while (pos >= 0 or upper != 0)
        {
            int posSum = 0;
            for (int n = N - 1; n >= 0; n--)
            {
                int m = pos - n;
                if (m < 0 or m >= M)
                    posSum += 0;
                else
                    posSum += paper[m][n];
            }
            posSum += upper;
            upper = posSum / 10;
            res.push_back(posSum % 10 + '0');
            pos--;
        };
        return string(res.rbegin(), res.rend());
    };
};