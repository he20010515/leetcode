/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2024-04-01 20:17:43
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-04-07 11:38:25
 * @FilePath: /leetcode/acm/questions/HG1/main.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <cstddef>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

inline int m_mul_count(int a, int b, int c)
{
    // c_ij = sum_k a_ik * bkj k = 0-b;
    return a * c * b;
};

int main()
{
    int a, b;
    vector<pair<int, int>> shapes;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        shapes.push_back({a, b});
    };
    string expr;
    cin >> expr;
    stack<pair<int, int>> stk; //
    int res = 0;
    size_t index = 0;
    while (true)
    {
        switch (expr[index])
        {
        case '(':
            // 什么都不做
            break;
        case ')':
            // 出栈
            stk.pop();
            break;
        default:
            // 入栈
            break;
        }
    }
}
// 64 位输出请用 printf("%lld")