/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-03 14:11:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 17:11:24
 * @FilePath: /leetcode/questions/2.addTwoNumbers/env.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
        : val(0), next(nullptr) {}
    ListNode(int x)
        : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next)
        : val(x), next(next) {}
    ListNode(int *x, int size)
    {
        ListNode *p = this;
        this->val = x[0];
        for (int i = 0; i < size - 1; i++)
        {
            p->next = new ListNode(x[i + 1]);
            p = p->next;
        }
    }
    bool operator==(ListNode &other)
    {
        ListNode *p = this, *q = &other;
        if ((not p) or (not q)) // 有一个为空则直接返回false
            return false;
        // 节点值相等且下一个节点都非空
        if (p->val == q->val and p->next == nullptr and q->next == nullptr)
        {
            return true;
        }

        while ((p->val == q->val) and (p->next != nullptr) and (q->next != nullptr))
        {
            p = p->next;
            q = q->next;
            // 如果到最后一个节点了, 且之前都相等, 那么返回true
            if (p->next == nullptr and q->next == nullptr)
                return true;
        }
        return false;
    }
    friend std::ostream &operator<<(std::ostream &out, ListNode *other)
    {
        if (other == nullptr)
        {
            out << "nullptr";
            return out;
        }
        ListNode *p = other;
        out << other->val << "->";
        while (p->next != nullptr)
        {
            p = p->next;
            out << p->val << "->";
            if (p->next == nullptr)
            {
                out << "nullptr";
            }
        }
        return out;
    }
};