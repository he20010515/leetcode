/*
 * @Author: heyuwei he2001015@163.com
 * @Date: 2024-02-27 21:26:47
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-30 18:51:01
 * @FilePath: /leetcode/questions/twosum/solution.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "BinaryTree.hpp"
#include <deque>
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

        vector<TreeNode *> curlayer, nextLayer;
        curlayer.push_back(root);
        vector<vector<int>> res;

        while (not curlayer.empty())
        {
            vector<int> curans;
            for (auto &p : curlayer)
            {
                curans.push_back(p->val);
                if (p->left)
                    nextLayer.push_back(p->left);
                if (p->right)
                    nextLayer.push_back(p->right);
            }
            res.push_back(curans);
            curlayer.clear();
            swap(curlayer, nextLayer);
        }
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