/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // 递归
        // if (root == nullptr) {
        //     root = new TreeNode(val);
        //     return root;
        // }
        //
        // if (root->val > val) {
        //     root->left = insertIntoBST(root->left, val);
        // }
        // else {
        //     root->right = insertIntoBST(root->right, val);
        // }
        //
        // return root;

        // 迭代
        if(root == nullptr) {
            root = new TreeNode(val);
            return root;
        }
        TreeNode *cur = root, *parent;
        while (cur != nullptr) {
            parent = cur;
            if (cur->val > val) {
                cur = cur->left;
            }
            else {
                cur = cur->right;
            }
        }
        if (parent->val > val)  {
            parent->left = new TreeNode(val);
        }
        else {
            parent->right = new TreeNode(val);
        }

        return root;
    }
};
// @lc code=end
