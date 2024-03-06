/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-03 14:11:08
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-03 16:21:37
 * @FilePath: /leetcode/questions/2.addTwoNumbers/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "env.hpp"

class Solution
{
public:
    ListNode *sol(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1, *q = l2;
        ListNode *res = new ListNode(0);
        ListNode *r = res;
        int upflag = 0;
        while (p != nullptr or q != nullptr)
        {
            auto pval = p ? p->val : 0;
            auto qval = q ? q->val : 0;
            r->val = (pval + qval + upflag) % 10;
            upflag = (pval + qval + upflag) / 10;
            if ((p and p->next != nullptr) or (q and q->next != nullptr) or upflag)
            {
                r->next = new ListNode(upflag);
            }
            if (p != nullptr)
                p = p->next;
            if (q != nullptr)
                q = q->next;
            r = r->next;
        }

        return res;
    }
};