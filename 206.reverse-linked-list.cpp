/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        // do the iterative method
        ListNode *prev = nullptr;
        ListNode *next = head; /// tmp

        /// haed is the curr
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        } // while
        return prev;
    }
};
// @lc code=end
