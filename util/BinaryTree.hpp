/*
 * @Author: heyuwei he20010515@163.com
 * @Date: 2024-03-26 17:48:35
 * @LastEditors: heyuwei he20010515@163.com
 * @LastEditTime: 2024-03-26 22:30:59
 * @FilePath: /leetcode/util/BinaryTree.hpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "ListNode.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <queue>
#pragma once
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode()
        : val(0), left(nullptr), right(nullptr){};
    TreeNode(int x)
        : val(x), left(nullptr), right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right){};
};

namespace BT
{

inline size_t deeptree(const TreeNode *t)
{
    if (t == nullptr)
        return 0;
    return std::max(deeptree(t->left) + 1, deeptree(t->right) + 1);
}

struct Block_t
{
    enum
    {
        BLACK = 0,
        LEFT,
        RIGHT,
        VALUE
    } blocktype;
    const TreeNode *p;
};
inline void fillbuffer(const TreeNode *t, Block_t *buffer, int i, int j, const int width, const int height)
{
    int ti, tj;
    if (t == nullptr)
        return;
    buffer[i * width + j].blocktype = Block_t::VALUE;
    buffer[i * width + j].p = t;
    if (t->left)
        for (ti = i + 1, tj = j - 1; tj > j - (height - i + 1) / 2; tj--)
        {
            buffer[ti * width + tj].blocktype = Block_t::LEFT;
            ti++;
        }
    if (t->right)
    {
        for (ti = i + 1, tj = j + 1; tj < j + (height - i + 1) / 2; tj++)
        {
            buffer[ti * width + tj].blocktype = Block_t::RIGHT;
            ti++;
        }
    }
    fillbuffer(t->left, buffer, ti, j - (height - i + 1) / 2, width, height);
    fillbuffer(t->right, buffer, ti, j + (height - i + 1) / 2, width, height);
}
inline void _printer(std::ostream &out, const TreeNode *root)
{

    int i, j;
    const int deepth = deeptree(root);
    const int width = (2 << deepth) - 3;
    const int height = (2 << (deepth - 1)) - 1;
    Block_t *buffer = (Block_t *)malloc(sizeof(Block_t) * width * height);
    memset(buffer, 0, (width * height) * sizeof(Block_t));
    fillbuffer(root, buffer, 0, (width - 1) / 2, width, height);
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (buffer[i * width + j].blocktype == Block_t::LEFT)
                out << "/";
            else if (buffer[i * width + j].blocktype == Block_t::RIGHT)
                out << "\\";
            else if (buffer[i * width + j].blocktype == Block_t::BLACK)
                out << " ";
            else
                out << buffer[i * width + j].p->val;
        }
        out << std::endl;
    }
    free(buffer);
}
} // namespace BT

inline std::ostream &operator<<(std::ostream &out, TreeNode *root)
{
    BT::_printer(out, root);
    return out;
}
#define Placeholder std::numeric_limits<int>::min()

#define BinaryTreeLayerOrder(...) __BinaryTreeHelper(__VA_ARGS__)

template <typename... Nums>
constexpr TreeNode *__BinaryTreeHelper(Nums... nums)
{
    int arr[] = {nums...};
    constexpr int size = sizeof...(nums);
    if (size == 0)
        return nullptr;
    std::array<TreeNode *, size> treeNodes;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == Placeholder)
            treeNodes[i] = nullptr;
        else
            treeNodes[i] = new TreeNode(arr[i]);
    }
    int index = 0;
    TreeNode *root = treeNodes[index++];
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty() && index < size)
    {
        TreeNode *current = q.front();
        q.pop();

        if (current)
        {
            current->left = treeNodes[index++];
            if (current->left)
                q.push(current->left);

            if (index < size)
            {
                current->right = treeNodes[index++];
                if (current->right)
                    q.push(current->right);
            }
        }
    }
    return root;
}