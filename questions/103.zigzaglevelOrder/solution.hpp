/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-30 21:08:40
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include <deque>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> sol(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        deque<TreeNode *> dq;
        vector<vector<int>> res;
        dq.push_back(root);
        int level = 0;
        while (!dq.empty())
        {
            auto cur_dqsize = dq.size();
            vector<int> cur_level;
            for (int i = 0; i < cur_dqsize; i++)
            {
                auto node = dq.front();
                dq.pop_front();
                cur_level.push_back(node->val);
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
            if (level % 2 != 0)
                cur_level = vector<int>(cur_level.rbegin(), cur_level.rend());
            res.push_back(cur_level);
            level++;
        };
        return res;
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