/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *deleteOneNode(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        if (root->right == nullptr)
            return root->left;
        TreeNode *cur = root->right;
        while (cur->left) {
            cur = cur->left;
        }
        cur->left = root->left;

        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *cur = root, *father = nullptr;
        while (cur->val != key) {
            father = cur;
            if (cur->val > key) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
            if (cur == nullptr)  // 1.没找到key
                return root;
        }
        if (father == nullptr) {
            return deleteOneNode(cur);
        }
        if (father->left == cur) {
            father->left = deleteOneNode(cur);
        }
        if (father->right == cur) {
            father->right = deleteOneNode(cur);
        }

        return root;
    }
};
// @lc code=end
