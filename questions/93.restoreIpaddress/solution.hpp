/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 17:36:38
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<string> sol(string s)
    {
        std::vector<int> path; // [0,path[0]), [path[1],path[2]), [path[2],path[3]), [path[3],path[4]),
        std::vector<string> res;
        dfs(s, path, res);
        return res;
    }
    void dfs(string &s, vector<int> &path, std::vector<string> &res, int begin = 0)
    {
        // 递归推出
        if (path.size() > 4 or (path.size() < 4 and begin == s.size())) // 无效答案, 分的太细或者是不够分
            return;
        if (path.size() == 4 and begin == s.size()) // 到达终点分好了
        {
            auto buf = s.substr(0, 0 + path[0]) + "." +
                       s.substr(path[0], path[1] - path[0]) + "." +
                       s.substr(path[1], path[2] - path[1]) + "." +
                       s.substr(path[2], path[3] - path[2]);
            res.push_back(std::move(buf));
        }

        // 填一个长度为1的段
        if (true)
        {
            path.push_back(begin + 1);
            dfs(s, path, res, begin + 1);
            path.pop_back();
        }
        // 填一个长度为2的段
        if (begin < s.size() - 1 and s[begin] != '0') // 不能有前导0
        {
            path.push_back(begin + 2);
            dfs(s, path, res, begin + 2);
            path.pop_back();
        }

        // 填一个长度为3的段
        auto thr = (s[begin] - '0') * 100 + (s[begin + 1] - '0') * 10 + (s[begin + 2] - '0');
        if (begin < s.size() - 2 and s[begin] != '0' and thr <= 255) // 不能有前导0, 而且s[begin]*100 + s[begin+1]*10+s[begin+2] <=255;
        {
            path.push_back(begin + 3);
            dfs(s, path, res, begin + 3);
            path.pop_back();
        }
        return;
    }
};