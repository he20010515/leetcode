/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-27 09:27:58
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include <map>
#include <vector>

// 二叉查找树（英语：Binary Search Tree），也称为二叉搜索树、有序二叉树（ordered binary tree）或排序二叉树（sorted binary tree），是指一棵空树或者具有下列性质的二叉树：

// 若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
// 若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
// 任意节点的左、右子树也分别为二叉查找树；
using namespace std;
class Solution
{
public:
    static map<pair<int, int>, vector<TreeNode *>> memo;
    vector<TreeNode *> sol(int n)
    {
        if (memo.contains({1, n}))
            return memo[{1, n}];
        backtrack(1, n);
        return memo[{1, n}];
    };
    vector<TreeNode *> backtrack(int l, int r)
    {
        if (l > r)
            return {nullptr};
        if (memo.contains({l, r}))
            return memo[{l, r}];

        vector<TreeNode *> res;
        for (int i = l; i <= r; i++)
        {
            vector<TreeNode *> leftTrees = backtrack(l, i - 1);
            vector<TreeNode *> rightTrees = backtrack(i + 1, r);
            for (auto &p : leftTrees)
                for (auto &q : rightTrees)
                    res.push_back(new TreeNode(i, p, q));
        };
        return memo[{l, r}] = res;
    }
};

map<pair<int, int>, vector<TreeNode *>> Solution::memo = {};
