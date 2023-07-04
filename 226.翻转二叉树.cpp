/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
#include <algorithm>
#include <stack>

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
    void exchange(TreeNode *cur) {
        if (cur == nullptr)
            return;
        swap(cur->left, cur->right);
        exchange(cur->left);
        exchange(cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {

        // 前序遍历
        stack<TreeNode*> st;
        if (root == nullptr) {
            return root;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode *tmp = st.top();
            st.pop();
            swap(tmp->left, tmp->right);
            if (tmp->left) st.push(tmp->left);
            if (tmp->right) st.push(tmp->right);
        }

        return root;

        // 递归法
        // exchange(root);
        // return root;


        // 深度优先遍历
        // if (root == nullptr) {
        //     return root;
        // }
        // queue<TreeNode*> qu;
        // qu.push(root);
        // while (!qu.empty()) {
        //     TreeNode *cur;
        //     cur = qu.front();
        //     qu.pop();
        //     swap(cur->left, cur->right);
        //     if (cur->left != nullptr) {
        //         qu.push(cur->left);
        //     }
        //     if (cur->right != nullptr) {
        //         qu.push(cur->right);
        //     }
        // }
        //
        // return root;
    }
};
// @lc code=end
