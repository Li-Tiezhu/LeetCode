/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int getMinDepth(TreeNode *root, int depth) {
        // 错误：左右节点都为null的情况才作数
        // if (root == nullptr) {
        //     return depth;
        // }
        // int left = getMinDepth(root->left, depth + 1);
        // int right = getMinDepth(root->right, depth + 1);
        // if (left < right) {
        //     return left;
        // }
        // else {
        //     return right;
        // }

        if (root->left == nullptr && root->right == nullptr)
            return depth;
        if (root->left == nullptr) {
            return getMinDepth(root->right, depth + 1);
        }
        else if (root->right == nullptr) {
            return getMinDepth(root->left, depth + 1);
        }
        else {
            int left = getMinDepth(root->left, depth + 1);
            int right = getMinDepth(root->right, depth + 1);
            if (left < right) {
                return left;
            }
            else {
                return right;
            }
        }
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return getMinDepth(root, 1);

        // 层序迭代
        // if (root == nullptr) {
        //     return 0;
        // }
        //
        // queue<TreeNode*> qu;
        // int depth = 0;
        // qu.push(root);
        // int size = 1;
        // while (!qu.empty()) {
        //     depth++;
        //     int tmp_size = 0;
        //     while (size--) {
        //         TreeNode *tmp = qu.front();
        //         qu.pop();
        //         if (tmp->left == nullptr && tmp->right == nullptr) {
        //             return depth;
        //         }
        //         if (tmp->left != nullptr) {
        //             tmp_size++;
        //             qu.push(tmp->left);
        //         }
        //         if (tmp->right != nullptr) {
        //             tmp_size++;
        //             qu.push(tmp->right);
        //         }
        //     }
        //
        //     size = tmp_size;
        // }
        //
        // return depth;
    }
};
// @lc code=end
