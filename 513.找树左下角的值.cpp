/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int floor_cur = 0;
    int result;
    void findValue(TreeNode* root, int floor) {
        if (root->left == nullptr && root->right == nullptr) {
            if (floor_cur < floor) {
                floor_cur = floor;
                result = root->val;
            }
            return;
        }
        if (root->left != nullptr) {
            findValue(root->left, floor + 1);
        }
        if (root->right != nullptr) {
            findValue(root->right, floor + 1);
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        // 递归
        // findValue(root, 1);
        // return result;

        // 迭代
        queue<TreeNode*> qu;
        qu.push(root);
        int size = 1;
        while (!qu.empty()) {
            TreeNode *tmp;
            int tmp_size = 0;
            bool flag = false;
            while (size--) {
                tmp = qu.front();
                qu.pop();
                if (flag == false) {
                    result = tmp->val;
                    flag = true;
                }
                if (tmp->left != nullptr) {
                    qu.push(tmp->left);
                    tmp_size++;
                }
                if (tmp->right != nullptr) {
                    qu.push(tmp->right);
                    tmp_size++;
                }
            }
            size = tmp_size;
        }

        return result;
    }
};
// @lc code=end
