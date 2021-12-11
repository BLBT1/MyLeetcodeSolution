/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        //* this problem has 3 parts
        //* 1. find the mid of the given list (fast-slow ptrs)
        //* 2. break thae mid and reverse the second list
        //* 3. alternatively take nodes to construct a new list

        if (!head || !head->next)
            return;

        // find the mid ptr
        ListNode *mid = nullptr;
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr &&
               fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        } // while
        mid = slow;

        // break from mid and reverse the second list
        ListNode *l2 = mid->next;
        mid->next = nullptr;

        // reverse the list by iterative method
        // in this case l2 is head;
        ListNode *prev = nullptr, *next;
        ListNode *curr = l2;

        while (l2 != nullptr)
        {
            next = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = next;
        } //while
        l2 = prev;

        ListNode *l1 = head;

        // alternatively take node to construct new list;
        while (l2->next || l1->next)
        {
            if (l1)
            {
                next = l1->next;
                l1->next = l2;
                l1 = next;
            }
            if (l2)
            {
                next = l2->next;
                l2->next = l1;
                l2 = next;
            }
        } //while
    }
};
// @lc code=end
