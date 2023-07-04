/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <vector>
#include <climits>
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
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode* root) {
        // 迭代法
        if (root == nullptr) return true;
        stack<int> st;
        st.push(root);
        while (!st.empty()) {

        }

        // 递归法
        // if (root == nullptr)
        //     return true;
        // bool left = isValidBST(root->left);
        //
        // if (pre == nullptr)
        //     pre = root;
        // else {
        //     if (pre->val < root->val) {
        //         pre = root;
        //     }
        //     else {
        //         return false;
        //     }
        // }
        //
        // bool right = isValidBST(root->right);
        //
        // return left && right;
    }
};
// @lc code=end
