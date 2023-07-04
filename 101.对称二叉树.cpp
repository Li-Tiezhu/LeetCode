/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right != nullptr)
            return false;
        else if (left != nullptr && right == nullptr)
            return false;
        else if (left == nullptr && right == nullptr)
            return true;
        else if (left->val != right->val)
            return false;
        bool outSide = compare(left->left, right->right);
        bool inSide = compare(left->right, right->left);

        return outSide && inSide;
    }

    bool isSymmetric(TreeNode *root) {
        // queue迭代法
        queue<TreeNode *> qu;
        qu.push(root->left);
        qu.push(root->right);
        while (!qu.empty()) {
            TreeNode *leftPtr = qu.front();
            qu.pop();
            TreeNode *rightPtr = qu.front();
            qu.pop();

            if (leftPtr == nullptr && rightPtr != nullptr)
                return false;
            else if (leftPtr != nullptr && rightPtr == nullptr)
                return false;
            else if (leftPtr == nullptr && rightPtr == nullptr)
                continue;
            else if (leftPtr->val != rightPtr->val) {
                return false;
            }

            // 此时两个值必相等
            qu.push(leftPtr->left);
            qu.push(rightPtr->right);
            qu.push(leftPtr->right);
            qu.push(rightPtr->left);
        }

        return true;

        // 递归
        // return compare(root->left, root->right);
    }
};
// @lc code=end
