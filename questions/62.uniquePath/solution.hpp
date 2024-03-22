/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-21 21:17:31
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *sol(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        ListNode virtualHead;
        virtualHead.next = head;
        ListNode *p = head, *ret;
        int len = 1;
        while (p->next != nullptr)
        {
            p = p->next;
            len++;
        };
        k = k % len;
        if (k == 0)
            return virtualHead.next;

        // 此时首尾相接成环
        p->next = virtualHead.next;
        // 再走n-k步断开
        for (int i = 0; i < len - k; i++)
        {
            p = p->next;
        };
        ret = p->next;
        p->next = nullptr;
        return ret;
    }
};