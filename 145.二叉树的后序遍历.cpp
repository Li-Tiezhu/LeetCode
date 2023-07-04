/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
#include <iterator>
#include <vector>
#include <stack>
#include <algorithm>

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
    // 递归法
    // void digui (TreeNode *cur, vector<int> &ret) {
    //     if (cur == nullptr) {
    //         return;
    //     }
    //     digui(cur->left, ret);
    //     digui(cur->right, ret);
    //     ret.push_back(cur->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     digui(root, result);
    //
    //     return result;
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> result;

        if (root == nullptr) {
            return result;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            result.push_back(node->val);
            st.pop();
            if (node->left) {
                st.push(node->left);
            }
            if (node->right) {
                st.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
