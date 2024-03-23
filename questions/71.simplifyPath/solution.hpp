/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-23 18:51:27
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string sol(string path)
    {
        const int pathsize = path.size();
        vector<string> stack;
        int index = 0;
        while (index < path.size())
        {
            if (path[index] == '/')
            {
                index++;
                continue;
            }
            if (path[index] == '.' and (index + 1 == pathsize or path[index + 1] == '/')) // /./当前目录, 什么都不做
            {
                index += 2;
                continue;
            }
            if (path[index] == '.' and path[index + 1] == '.' and (index + 2 == pathsize or path[index + 2] == '/')) // .. 上一级目录, 出栈
            {
                index += 3;
                if (stack.size() >= 1)
                    stack.pop_back();
                continue;
            }
            // 其他情况: 入栈
            auto start = index;
            while (index < pathsize and path[index] != '/')
                index++;
            stack.push_back(path.substr(start, index - start));
        };
        string res = "";
        if (stack.size() == 0)
            return "/";
        for (auto &dirname : stack)
        {
            res += "/" + dirname;
        };
        return res;
    };
};