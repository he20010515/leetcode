/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 17:35:46
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include "env.hpp"
#include <vector>
using namespace std;
class Solution
{
public:
    ListNode *sol(ListNode *list1, ListNode *list2)
    {
        auto compare = [](ListNode *node1, ListNode *node2)
        {
            if (node1 != nullptr and node2 != nullptr)
                return node1->val < node2->val ? node1 : node2;
            if (node1 == nullptr and node2 == nullptr)
                return (ListNode *)nullptr;
            return node1 ? node1 : node2;
        };
        ListNode *res = nullptr;
        auto pointer = res, p = list1, q = list2;
        while (!(p == nullptr and q == nullptr))
        {
            auto small = compare(p, q);
            if (small == p)
                p = p->next;
            else
                q = q->next;
            if (pointer == nullptr) // 处理首节点
            {
                pointer = new ListNode(*small);
                res = pointer;
            }
            else
            {
                pointer->next = new ListNode(*small);
                pointer = pointer->next;
            }
        }

        return res;
    }
};