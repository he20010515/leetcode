/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-27 16:32:24
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include "basic.hpp"
#include <algorithm>
#include <limits>
using namespace std;
class Solution
{
public:
    bool sol(TreeNode *root)
    {
        return isBST(root);
    };
    bool isBST(TreeNode *node)
    {
        if (node == nullptr)
            return true;
        if (treemax(node->left) < node->val and treemin(node->right) > node->val)
            return isBST(node->left) and
                   isBST(node->right);
        return false;
    }
    int treemax(TreeNode *node)
    {
        if (node == nullptr)
            return numeric_limits<int>::min();
        int lmax = treemax(node->left);
        int rmax = treemax(node->right);
        return max(max(lmax, rmax), node->val);
    };
    int treemin(TreeNode *node)
    {
        if (node == nullptr)
            return numeric_limits<int>::max();
        int lmin = treemin(node->left);
        int rmin = treemin(node->right);
        return min(min(lmin, rmin), node->val);
    }
};