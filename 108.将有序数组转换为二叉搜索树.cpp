/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
#include <ios>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //递归法
        // if (nums.size() == 1) {
        //     return new TreeNode(nums[0]);
        // }
        // if (nums.size() == 0) {
        //     return nullptr;
        // }
        //
        // TreeNode *root = new TreeNode(nums[nums.size()/2]);
        // vector<int> tmp_left(nums.begin(), nums.begin()+nums.size()/2);
        // root->left = sortedArrayToBST(tmp_left);
        // vector<int> tmp_right(nums.begin() + nums.size()/2 + 1, nums.end());
        // root->right = sortedArrayToBST(tmp_right);
        //
        // return root;

        // 迭代法
        if (nums.size() == 0) return nullptr;

        TreeNode *root = new TreeNode(0);
        queue<TreeNode *> nodeQue;
        queue<int> leftQue;
        queue<int> rightQue;
        nodeQue.push(root);
        leftQue.push(0);
        rightQue.push(nums.size() - 1);

        while (!nodeQue.empty()) {
            TreeNode *curNode = nodeQue.front();
            nodeQue.pop();
            int left = leftQue.front(); leftQue.pop();
            int right = rightQue.front(); rightQue.pop();
            int mid = left + ((right - left) / 2);

            curNode->val = nums[mid];

            if (left <= mid -1) {
                curNode->left = new TreeNode(0);
                nodeQue.push(curNode->left);
                leftQue.push(left);
                rightQue.push(mid - 1);
            }
            if (right >= mid + 1) {
                curNode->right = new TreeNode(0);
                nodeQue.push(curNode->right);
                leftQue.push(mid + 1);
                rightQue.push(right);
            }
        }

        return root;
    }
};
// @lc code=end
