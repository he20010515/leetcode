/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 14:16:04
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "ListNode.hpp"
#include "basic.hpp"
using namespace std;
class Solution
{
public:
    ListNode *sol(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode VirtualHead;
        VirtualHead.next = head;

        ListNode *slow = &VirtualHead, *fast = VirtualHead.next;
        while (fast != nullptr and fast->next != nullptr)
        {
            while (fast->next != nullptr and fast->next->val == fast->val)
                fast = fast->next;
            slow->next = fast;
            slow = slow->next;
            fast = fast->next;
        };
        return VirtualHead.next;
    };
};