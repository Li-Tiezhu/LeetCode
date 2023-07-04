/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int target;
    bool findPath(TreeNode *root, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            if ((sum + root->val) == target) {
                return true;
            }
            return false;
        }

        if (root->left != nullptr) {
            bool left = findPath(root->left, sum + root->val);
            if (left == true) {
                return true;
            }
        }
        if (root->right != nullptr) {
            bool right = findPath(root->right, sum + root->val);
            if (right == true) {
                return true;
            }
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 递归法
        // if (root == nullptr)
        //     return false;
        // target = targetSum;
        // return findPath(root, 0);

        // 深度优先遍历
        if (root == nullptr)
            return false;
        stack<TreeNode*> st;
        stack<int> stVal;
        st.push(root);
        stVal.push(root->val);
        while (!st.empty()) {
            TreeNode *tmp =  st.top();
            st.pop();
            int val = stVal.top();
            stVal.pop();
            if (tmp->left == nullptr && tmp->right == nullptr) {
                if (val == targetSum)
                    return true;
            }
            if (tmp->right != nullptr) {
                st.push(tmp->right);
                stVal.push(val + tmp->right->val);
            }
            if (tmp->left != nullptr) {
                st.push(tmp->left);
                stVal.push(val + tmp->left->val);
            }
        }

        return false;
    }
};
// @lc code=end
