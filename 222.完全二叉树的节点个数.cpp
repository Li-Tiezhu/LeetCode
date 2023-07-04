/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int count(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int left = count(root->left);
        int right = count(root->right);

        return left + right + 1;
    }

    int countNodes(TreeNode* root) {
        // 递归遍历
        // return count(root);

        // 利用q完全二叉树的性质递归迭代
        if (root == nullptr)
            return 0;
        int leftDepth = 0, rightDepth = 0;
        TreeNode *left = root->left, *right = root->right;

        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right) {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) {
            return (2 << leftDepth) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;

        // 层序迭代法
        // int count = 0;
        // if (root == nullptr) {
        //     return count;
        // }
        // queue<TreeNode *> qu;
        // int size = 1;
        // count += size;
        // qu.push(root);
        // while (size != 0) {
        //     int tmp_size = 0;
        //     TreeNode *tmp;
        //     while (size--) {
        //         tmp = qu.front();
        //         qu.pop();
        //         if (tmp->left != nullptr) {
        //             qu.push(tmp->left);
        //             tmp_size++;
        //         }
        //         if (tmp->right != nullptr) {
        //             qu.push(tmp->right);
        //             tmp_size++;
        //         }
        //     }
        //     size = tmp_size;
        //     count += tmp_size;
        // }
        //
        // return count;
    }
};
// @lc code=end
