/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int min = INT_MAX;
    TreeNode *cur = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr)
            return min;
        int left = getMinimumDifference(root->left);

        if (cur == nullptr)
            cur = root;
        else if ((root->val - cur->val) < min) {
            min = root->val - cur->val;
        }
        cur = root;

        int right = getMinimumDifference(root->right);

        return min;
    }
};
// @lc code=end
