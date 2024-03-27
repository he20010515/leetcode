/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 23:15:25
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include "basic.hpp"
#include <algorithm>
#include <ranges>
#include <unordered_set>
#include <vector>

// 二叉查找树（英语：Binary Search Tree），也称为二叉搜索树、有序二叉树（ordered binary tree）或排序二叉树（sorted binary tree），是指一棵空树或者具有下列性质的二叉树：

// 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
// 若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
// 任意节点的左、右子树也分别为二叉查找树；
using namespace std;
class Solution
{
public:
    vector<TreeNode *> sol(int n)
    {
        vector<bool> usedvalue(n + 1, false);
        vector<int> numbers(n);
        for (int i = 1; i <= n; i++)
            numbers[i - 1] = i;

        return {};
    };
    void build(TreeNode *node, vector<bool> &usedvalue, vector<int> &numbers)
    {
        if (usedvalue.size() == numbers.size())
            return;
        for (auto number : numbers)
        {
            if (usedvalue[number])
                continue;
            if (number < node->val)
            {
                node->left = new TreeNode(number);
                usedvalue[number] = true;
                build(node->left, usedvalue, numbers);
                usedvalue[number] = false;
            }
            else
            {
                node->right = new TreeNode(number);
                usedvalue[number] = true;
                build(node->right, usedvalue, numbers);
                usedvalue[number] = false;
            }
        }
    }
};