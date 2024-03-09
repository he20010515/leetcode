/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 18:34:42
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
    int stack_size = 0;
    int target_num = 0;
    vector<string> sol(int a)
    {
        auto res = vector<string>();
        auto buffer = string();
        stack_size = 0;
        target_num = a;
        back_track(res, buffer, 0);
        return res;
    }
    void back_track(vector<string> &res, string &buffer, int leftnum)
    {
        if (leftnum == target_num and stack_size == 0)
        {
            res.push_back(buffer);
            return;
        }
        // 此处有两个选择, 插入 '(' 或者 ')'
        // 如果栈空只能插入 (;
        // 否则考虑当前深度, 如果当前左括号数量等于a了, 那么只能插入右括号, 否则左右都行.

        // 如果栈空只能插入 (;
        if (stack_size == 0)
        {
            stack_size += 1;
            buffer.push_back('(');
            back_track(res, buffer, leftnum + 1);
            buffer.pop_back();
            stack_size -= 1;
        }
        else
        {
            // 否则考虑当前深度, 如果当前左括号数量等于a了, 那么只能插入右括号, 否则左右都行.
            if (leftnum < target_num)
            {
                // 插入'(' 或者 插入')';

                // '('
                buffer.push_back('(');
                stack_size += 1;
                back_track(res, buffer, leftnum + 1);
                buffer.pop_back();
                stack_size -= 1;

                // ')'
                buffer.push_back(')');
                stack_size -= 1;
                back_track(res, buffer, leftnum);
                buffer.pop_back();
                stack_size += 1;
            }
            else //
            {
                buffer.push_back(')');
                stack_size -= 1;
                back_track(res, buffer, leftnum);
                buffer.pop_back();
                stack_size += 1;
            }
        }
    }
};