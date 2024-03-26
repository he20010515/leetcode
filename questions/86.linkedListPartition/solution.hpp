/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 15:45:13
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "ListNode.hpp"
#include "basic.hpp"
#include <algorithm>
using namespace std;
class Solution
{
public:
    ListNode *sol(ListNode *head, int x)
    {
        ListNode *p = head;
        ListNode v_l, v_beq;
        ListNode *p_l = &v_l, *p_beq = &v_beq;
        while (p != nullptr)
        {
            if (p->val < x)
            {
                p_l->next = p;
                p_l = p_l->next;
            }
            else
            {
                p_beq->next = p;
                p_beq = p_beq->next;
            }
            p = p->next;
        }
        p_l->next = v_beq.next;
        p_beq->next = nullptr;

        return v_l.next;
    };
};