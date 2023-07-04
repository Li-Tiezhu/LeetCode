/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <string>
#include <vector>
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
    void makeString(TreeNode* root, vector<string> &ve, string st) {
        string cur;
        if (st == "")
            cur = to_string(root->val);
        else
            cur = st + "->" + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ve.push_back(cur);
            return;
        }
        if (root->left != nullptr) {
            makeString(root->left, ve, cur);
        }
        if (root->right != nullptr) {
            makeString(root->right, ve, cur);
        }
    }

    void traversal(TreeNode *cur, vector<int> &path, vector<string> &result) {
        path.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            result.push_back(sPath);
            return;
        }
        if (cur->left != nullptr) {
            traversal(cur->left, path, result);
            path.pop_back();
        }
        else {
            traversal(cur->right, path, result);
            path.pop_back();
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ve;
        if (root == nullptr)
            return ve;

        // 自己的递归
        // makeString(root, ve, "");
        // return ve;

        // 代码随想录递归
        // vector<int> path;
        // traversal(root, path, ve);
        // return ve;

        // 深度优先遍历
        stack<TreeNode*> treeSt;
        stack<string> pathSt;
        treeSt.push(root);
        pathSt.push(to_string(root->val));

        while (!treeSt.empty()) {
            TreeNode *node = treeSt.top();
            treeSt.pop();
            string path = pathSt.top();
            pathSt.pop();
            if (node->left == nullptr && node->right == nullptr) {
                ve.push_back(path);
            }

            if (node->right != nullptr) {
                treeSt.push(node->right);
                pathSt.push(path + "->" + to_string(node->right->val));
            }
            if (node->left != nullptr) {
                treeSt.push(node->left);
                pathSt.push(path + "->" + to_string(node->left->val));
            }
        }

        return ve;
    }
};
// @lc code=end
