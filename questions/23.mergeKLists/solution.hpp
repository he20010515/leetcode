/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-09 21:00:43
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
    ListNode *sol(vector<ListNode *> lists)
    {
        auto pointers = vector<ListNode *>(lists);
        auto compare = [&](vector<ListNode *> &ps)
        {
            int smallest_index = -1;
            for (int index = 0; index < ps.size(); index++)
            {
                if (smallest_index != -1 and ps[index] != nullptr and ps[index]->val < ps[smallest_index]->val)
                {
                    smallest_index = index;
                }
                else if (smallest_index == -1 and ps[index] != nullptr)
                {
                    smallest_index = index;
                }
            }
            return smallest_index;
        };
        ListNode *head = nullptr, *q = head;
        while (true)
        {
            auto p = compare(pointers);
            if (p != -1)
            {
                if (head == nullptr)
                {
                    head = new ListNode(*pointers[p]);
                    q = head;
                }
                else
                {
                    q->next = new ListNode(*pointers[p]);
                    q = q->next;
                }
                pointers[p] = pointers[p]->next;
            }
            else
                break;
        }
        return head;
    }
};