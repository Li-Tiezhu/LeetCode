/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {
    }
};

class Solution {
   public:
    int ret = 0;
    int count(TreeNode *root) {
        if (root == nullptr)
            return 2;
        int left = count(root->left);
        int right = count(root->right);
        if (left == 2 && right == 2) {
            return 0;
        }
        if (left == 0 || right == 0) {
            ret++;
            return 1;
        }
        if (left == 1 || right == 1)
            return 2;

        return -1;
    }
    // 0：无覆盖
    // 1：安摄像头
    // 2：有覆盖
    int minCameraCover(TreeNode *root) {
        if (count(root) == 0)
            ret++;
        return ret;
    }
};
// @lc code=end
