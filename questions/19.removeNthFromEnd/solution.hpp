/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-03-03 14:11:08
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 16:02:31
 * @FilePath: /leetcode/questions/2.addTwoNumbers/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "env.hpp"

class Solution
{
public:
    ListNode *sol(ListNode *head, int n)
    {
        auto fast = head, slow = head;
        if (head->next == nullptr and n == 1)
            return nullptr;
        // 快慢指针
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == nullptr) // 倒数第size-1个, 也就是要删除第一个节点;
            return head->next;

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // 此时删除slow的下一个节点, 分情况讨论
        auto pre = slow->next->next;
        slow->next = pre;
        return head;
    }
};