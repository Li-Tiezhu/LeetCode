/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
#include <ios>
#include <iostream>
#include <queue>
#include <utility>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return nullptr;
        }
        else if (inorder.size() == 1) {
            return new TreeNode(inorder[0]);
        }
        int nodeVal = postorder[postorder.size() - 1];
        TreeNode *cur = new TreeNode(nodeVal);

        int i = 0;
        while (i < inorder.size() && inorder[i] != nodeVal ) {
            i++;
        }
        postorder.resize(postorder.size() - 1);

        vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
        vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + i);
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        cur->left = buildTree(leftInorder, leftPostorder);
        cur->right = buildTree(rightInorder, rightPostorder);
        return cur;
    }
};
// @lc code=end
