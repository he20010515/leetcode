/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-10 22:00:43
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include "env.hpp"
#include <__concepts/assignable.h>
#include <__memory/temporary_buffer.h>
#include <iterator>
#include <limits>
#include <tuple>
#include <vector>
using namespace std;
class Solution
{
public:
    ListNode *sol(ListNode *head, int k)
    {
        auto reverse = [](ListNode *begin, ListNode *end)
        {
            auto mid_pointer = begin->next,
                 fast_pointer = begin->next->next,
                 slow_pointer = begin;
            const auto stopflag = end->next;
            while (mid_pointer != stopflag)
            {
                mid_pointer->next = slow_pointer;

                slow_pointer = mid_pointer;
                mid_pointer = fast_pointer;
                if (fast_pointer == nullptr)
                    break;

                fast_pointer = fast_pointer->next;
            };
        };
        auto kstep = [](ListNode *q, int step)
        {
            for (int i = 0; i < step; i++)
            {
                if (q != nullptr)
                    q = q->next;
                else
                    return (ListNode *)nullptr;
            }
            return q;
        };

        //                     | begin             | end
        // virtualhead-> .. -> a -> b -> c -> d -> e -> f  -> ...

        //
        // virtualhead-> .. -> f -> e -> d -> c -> b -> a  -> ...
        if (head == nullptr or k == 1)
            return head;
        ListNode virtualhead;
        virtualhead.next = head;
        auto debug_var = vector<ListNode *>();
        auto p = &virtualhead;
        while (p != nullptr)
        {
            debug_var.push_back(p);
            p = p->next;
        }

        ListNode *ll, *rr, *l, *r;
        ll = &virtualhead;
        while ((r = kstep(ll, k)) != nullptr)
        {
            // 获取ll,rr,l,r 四个指针;
            rr = r->next;
            l = ll->next;
            // 翻转l到r
            reverse(l, r);
            // 将ll指向r; 将 l指向rr
            ll->next = r;
            l->next = rr;
            // 更新ll
            ll = l;
        }

        return virtualhead.next;
    }
};