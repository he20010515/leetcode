/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-25 14:13:16
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
        if (!head)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0, head);

        ListNode *cur = dummy;
        while (cur->next && cur->next->next)
        {
            if (cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};