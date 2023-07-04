#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> qu;
        if (root == nullptr) {
            return result;
        }
        qu.push(root);
        int num = 1;
        while (!qu.empty()) {
            vector<int> tmp;
            int tmp_cum = 0;
            while (num--) {
                TreeNode *cur = qu.front();
                qu.pop();
                tmp.push_back(cur->val);
                if (cur->left != nullptr) {
                    qu.push(cur->left);
                    tmp_cum++;
                }
                if (cur->right != nullptr) {
                    qu.push(cur->right);
                    tmp_cum++;
                }
            }
            num = tmp_cum;
            result.push_back(tmp);
        }

        return result;
    }
};
// @lc code=end
