#include <iostream>
#include <type_traits>
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // 循环判断的方法
        ListNode dummyA = ListNode(0);
        ListNode dummyB = ListNode(0);
        dummyA.next = headA;
        dummyB.next = headB;

        ListNode *A = &dummyA, *B = &dummyB;
        while (A->next != nullptr) {
            A = A->next;
            B = &dummyB;
            while (B->next != nullptr) {
                B = B->next;
                if (A == B) {
                    return A;
                }
            }
        }
        return nullptr;

        // 代码随想录对齐方法
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;

        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lenB > lenA) {
            std::swap(lenA, lenB);
            std::swap(curA, curB);
        }

        int gap = lenA - lenB;
        while(gap--) {
            curA = curA->next;
        }

        while(curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;

    }
};
// @lc code=end
