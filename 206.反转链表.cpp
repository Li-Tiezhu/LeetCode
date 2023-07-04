#include <iostream>
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 递归法
    ListNode *reverse(ListNode *pre, ListNode *cur) {
        if (cur == nullptr) {
            return pre;
        }
        ListNode *temp = cur->next;
        cur->next = pre;
        return reverse(cur, temp);
    }
    ListNode* reverseList(ListNode* head) {

        // 三个指针方法
        ListNode *one = head, *two, *three;
        if (one == NULL) {
            return NULL;
        }
        two = one->next;
        if (two == NULL) {
            return head;
        }
        three = two->next;
        if (three == NULL) {
            two->next = one;
            one->next = NULL;
            return two;
        }

        one->next = NULL;
        while (three != nullptr) {
            two->next = one;
            one = two;
            two = three;
            three = three->next;

        }
        two->next = one;
        return two;

        // 双指针方法
        ListNode *temp;
        ListNode *cur = head;
        ListNode *pre = NULL;

        while(cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;

        // 递归法，上面还定义了一个函数
        return reverse(nullptr, head);
    }
};
// @lc code=end
