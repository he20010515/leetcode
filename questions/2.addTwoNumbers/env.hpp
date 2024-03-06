/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-03 14:11:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-03 16:24:33
 * @FilePath: /leetcode/questions/2.addTwoNumbers/env.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(int *x, int size)
    {
        ListNode *p = this;
        this->val = x[size - 1];
        for (int offset = 0; offset < size - 1; offset++)
        {
            p->next = new ListNode(x[size - offset - 2]);
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
        ListNode *p = other;
        if (other == nullptr)
        {
            out << "nullptr";
            return out;
        }
        int length = 1;
        while (p->next != nullptr)
        {
            p = p->next;
            length++;
        }
        auto buffer = new char[length + 1];
        auto cursor = buffer;
        buffer[length] = '\0';
        cursor = buffer + length - 1;
        p = other;
        while (p != nullptr)
        {
            *cursor = p->val + '0';
            cursor--;
            p = p->next;
        }
        out << buffer;
        delete[] buffer;
        return out;
    }
};