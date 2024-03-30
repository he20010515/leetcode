/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-30 18:30:20
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include <stack>
using namespace std;
class Solution
{
public:
    bool sol(TreeNode *root)
    {
        return dfs(root, root);
    };
    bool dfs(TreeNode *p, TreeNode *q) // 判断两个数是否反转相等
    {
        if (p == nullptr and q == nullptr)
            return true;
        if (p == nullptr or q == nullptr)
            return false;
        // 节点值相同, 且p的左子树等于q
        return p->val == q->val and dfs(p->left, q->right) and dfs(p->right, q->left);
    }
};

// inline void dfs(TreeNode *root)
// {
//     if (root == nullptr)
//         return;
//     cout << root->val << endl;
//     dfs(root->left);
//     dfs(root->right);
// }