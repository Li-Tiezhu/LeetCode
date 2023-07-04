/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int convertSum(TreeNode *root, int father){
        if (root == nullptr) {
            return 0;
        }
        int right = convertSum(root->right, father);
        // NOTE:下面一行是错的
        // if (root->left == nullptr && root->right == nullptr)
        // 只要右边没有值就该返回father了
        if (root->right == nullptr) {
            root->val = right +root->val + father;
        }
        else {
            root->val = right + root->val;
        }
        if (root->left == nullptr)  {
            return root->val;
        }
        int left = convertSum(root->left, root->val);
        return left;
    }

    // NOTE: 直接使用中序遍历就可以了
    int curSum = 0;
    void traversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        traversal(root->right);
        root->val = root->val + curSum;
        curSum = root->val;
        traversal(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        // 递归1
        // convertSum(root, 0);

        // 递归2
        // traversal(root);

        // 迭代法
        int pre = 0;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->right;
            }
            else {
                cur = st.top();
                st.pop();
                cur->val += pre;
                pre = cur->val;
                cur = cur->left;
            }
        }
        return root;
    }
};
// @lc code=end
