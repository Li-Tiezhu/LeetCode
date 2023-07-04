/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode, *more = new ListNode;
        ListNode *less_t = less, *more_t = more;
        ListNode *temp = head;

        while(temp != NULL) {
            if(temp->val < x) {
                less_t->next = temp;
                less_t = less_t->next;
            }
            else {
                more_t->next = temp;
                more_t = more_t->next;
            }
            temp = temp->next;
        }
        more_t->next = nullptr;
        less_t->next = more->next;

        return less->next;
    }
};
// @lc code=end

