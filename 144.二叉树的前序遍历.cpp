/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
#include <vector>
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
    // 递归
    // void digui(TreeNode *cur, vector<int> &ret) {
    //     if (cur == nullptr) {
    //         return;
    //     }
    //     ret.push_back(cur->val);
    //     digui(cur->left, ret);
    //     digui(cur->right, ret);
    // }
    //
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     digui(root, result);
    //
    //     return result;
    // }

    // 迭代法
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;

        if (root == NULL) {
            return result;
        }

        st.push(root);
        while (!st.empty()) {
             TreeNode *node = st.top();
             st.pop();
             result.push_back(node->val);
             if (node->right) {
                st.push(node->right);
             }
             if (node->left) {
                st.push(node->left);
             }
        }

        return result;
    }
};
// @lc code=end
