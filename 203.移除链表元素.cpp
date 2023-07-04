/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = head;
        ListNode* ret = new ListNode;
        ListNode* ret_temp = ret;
        ListNode* del = nullptr;
        while (temp != NULL) {
            if (temp->val != val) {
                ret_temp->next = temp;
                ret_temp = ret_temp->next;
            }
            else {
                del = temp;
            }
            temp = temp->next;
            if (del != nullptr) {
                delete del;
            }
            del = nullptr;
        }
        ret_temp->next = nullptr;
        return ret->next;
    }
};
// @lc code=end
