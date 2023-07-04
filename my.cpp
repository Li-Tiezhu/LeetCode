#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <unordered_set>
#include <deque>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
        vector<int> leftInorder, rightInorder;
        int i = 0;
        while (i < inorder.size() && inorder[i] != nodeVal ) {
            leftInorder.push_back(inorder[i]);
            i++;
        }
        i++;
        while (i < inorder.size()) {
            rightInorder.push_back(inorder[i]);
            i++;
        }

        vector<int> leftPostorder, rightPostorder;
        i = postorder.size() - 2;
        while (i >= 0) {
            int j = 0;
            bool flag = false;
            while (j < leftInorder.size()) {
                if (leftInorder[j] == postorder[i]) {
                    flag = true;
                    break;
                }
                j++;
            }
            if (flag == true) {
                break;
            }
            i--;
        }
        int end = i;
        i = 0;
        while (i <= end) {
            leftPostorder.push_back(postorder[i]);
            i++;
        }
        while (i <= (postorder.size() - 2)) {
            rightPostorder.push_back(postorder[i]);
        }

        cur->left = buildTree(leftInorder, leftPostorder);
        cur->right = buildTree(rightInorder, rightPostorder);
        return cur;
    }
};

int main() {

    Solution solution;
    vector<int> inorder = vector<int>({3, 2, 1});
    vector<int> postorder = vector<int>({3, 2, 1});
    solution.buildTree(inorder, postorder);
    return 0;
}
