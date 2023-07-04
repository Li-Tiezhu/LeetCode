/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int flag = 0;
        ListNode *ret = new ListNode;
        ListNode *ret_temp = ret;
        ListNode *temp;
        int num = 0;

        while(1) {
            flag = -1;
            for(vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); it++) {
                if ((*it) == NULL)
                    continue;
                if (flag == -1) {
                    if ((*it) != NULL){
                        flag = it - lists.begin();
                    }
                    continue;
                }
                if ( (*it)->val <= (*(lists.begin() + flag))->val) {
                    flag = it - lists.begin();
                }
                if ((*it)->val == 64)
                    cout << "hello hhh" << endl;
            }
            if (flag == -1) {
                break;
            }
            ret_temp->next = *(lists.begin() + flag);
            ret_temp = ret_temp->next;
            *(lists.begin() + flag) = (*(lists.begin() + flag))->next;
        }
        ret_temp->next = NULL;
        return ret->next;

    }
};
// @lc code=end

