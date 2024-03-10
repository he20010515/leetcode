/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he2001015@163.com
 * @LastEditTime: 2024-03-10 14:28:01
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "basic.hpp"
#include "env.hpp"
#include <iterator>
#include <vector>
using namespace std;
class Solution
{
public:
    ListNode *sol(ListNode *head)
    {

        //                  first secod  | c
        // virtualhead-> .. -> a -> b -> c -> d
        // virtualhead-> .. -> b -> a -> d -> c
        if (head == nullptr)
            return nullptr;
        ListNode VitrualHead, *vhead = &VitrualHead;
        vhead->next = head;
        auto cur = vhead;
        while (cur->next != nullptr and cur->next->next != nullptr)
        {
            auto a = cur->next, b = a->next, c = b->next;
            cur->next = b;
            cur->next->next = a;
            cur->next->next->next = c;

            cur = cur->next->next;
        }
        return vhead->next;
    }
};