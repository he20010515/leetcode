/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-27 20:31:18
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include "basic.hpp"
#include <utility>
#include <vector>
using namespace std;
class Solution
{
public:
    TreeNode *sol(TreeNode *head)
    {
        auto buffer = vector<pair<int, TreeNode *>>();
        auto swaptwo = vector<int>();
        midorder(buffer, head);

        // 正常的BST应该是严格单调递增的序列;
        for (int index = 0; index < buffer.size() - 1; index++)
        {
            if (buffer[index + 1].first < buffer[index].first) // 如果出现单调减的情况,记录
                swaptwo.push_back(index);
        }
        if (swaptwo.size() == 1)
            swaptwo.push_back(swaptwo[0] + 1); // i, i+1;
        else
            swaptwo[1]++; // i, j+1

        std::swap(buffer[swaptwo[0]].second->val, buffer[swaptwo[1]].second->val);
        return head;
    }
    void midorder(vector<pair<int, TreeNode *>> &buffer, TreeNode *node)
    {
        if (node == nullptr)
            return;

        midorder(buffer, node->left);
        buffer.push_back({node->val, node});
        midorder(buffer, node->right);
    }
};