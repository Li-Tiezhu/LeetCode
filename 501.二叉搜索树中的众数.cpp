/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int curSum = 0, maxSum = 0;
    vector<int> result;
    TreeNode *cur = nullptr;
    void findOne(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        findOne(root->left);

        if (cur != nullptr) {
            if (cur->val == root->val) {
                curSum++;
            }
            else {  // 值不相同了
                curSum = 1;
            }
        }
        else {
            curSum++;
        }
        cur = root;

        if (curSum > maxSum) {  // 当前计算的长度大于最大长度
            maxSum = curSum;
            result.clear();
            result.push_back(cur->val);
        }
        else if (curSum == maxSum) {
            result.push_back(cur->val);
        }

        findOne(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        findOne(root);
        if (curSum > maxSum) {
            result.clear();
            result.push_back(cur->val);
        }

        return result;
    }
};
// @lc code=end
