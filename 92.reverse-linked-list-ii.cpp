/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        //* do it in one pass
        if (!head || !head->next)
            return head;

        // set dummy, its index is 0
        ListNode dummy(0, head);
        ListNode *curr = &dummy;

        // first part
        for (int i = 0; i < left - 1; ++i)
            curr = curr->next;

        // record l_prev and l
        ListNode *l_prev = curr;
        curr = curr->next;
        ListNode *l = curr;

        // the 2nd part, reverse
        ListNode *prev = nullptr;
        ListNode *next = curr;
        for (int i = left; i <= right; ++i)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } //for

        l_prev->next = prev;
        l->next = curr;

        return dummy.next;
    }
};
// @lc code=end
