/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <stack>
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
    vector<vector<int>> result;
    int target;
    void findPath(TreeNode *cur, int curSum, vector<int> curPath) {
        curPath.push_back(cur->val); // 对于路径d在调用之后才添加当前节点，避免左节点调用完成之后先弹出再弹入右节点的操作
        if (cur->left == nullptr && cur->right == nullptr) {
            if (curSum == target) {
                result.push_back(curPath);
            }
            return;
        }
        if (cur->left != nullptr) {
            findPath(cur->left, curSum + cur->left->val, curPath);
        }
        if (cur->right != nullptr) {
            findPath(cur->right, curSum + cur->right->val, curPath);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // 递归
        if (root == nullptr)
            return result;
        target = targetSum;
        vector<int> tmp;
        findPath(root, root->val, tmp);
        return result;

    }
};
// @lc code=end
