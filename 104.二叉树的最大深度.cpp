/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int deep(TreeNode *root, int depth) {
        if (root == nullptr)
            return depth;
        int left = deep(root->left, depth + 1);
        int right = deep(root->right, depth + 1);
        if (left > right) {
            return left;
        }
        else {
            return right;
        }
    }
    int maxDepth(TreeNode* root) {
        // 递归法
        int result = deep(root, 0);

        return result;

        // 层序遍历
        // queue<TreeNode*> qu;
        // if (root == nullptr)
        //     return 1;
        // int deep = 0;
        // qu.push(root);
        // int size = 1;
        // while (!qu.empty()) {
        //     int tmp_size = 0;
        //     while (size--) {
        //         TreeNode* tmp = qu.front();
        //         qu.pop();
        //         if (tmp->left != nullptr) {
        //             tmp_size++;
        //             qu.push(tmp->left);
        //         }
        //         if (tmp->right != nullptr) {
        //             tmp_size++;
        //             qu.push(tmp->right);
        //         }
        //     }
        //     size = tmp_size;
        //     deep++;
        // }
        //
        // return deep;
    }
};
// @lc code=end
