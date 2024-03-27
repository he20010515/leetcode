/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 22:35:37
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include "basic.hpp"
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sol(TreeNode *root)
    {
        vector<int> buffer;
        inorderVisit(root, buffer);
        return buffer;
    }
    void inorderVisit(TreeNode *node, vector<int> &buffer)
    {
        if (node == nullptr)
            return;
        inorderVisit(node->left, buffer);
        buffer.push_back(node->val);
        inorderVisit(node->right, buffer);
    }
};