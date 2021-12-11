/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        //* idea: fast ptr && slow ptr
        //* first determine if exists a cycle (if they meet)
        //* from meet point to begin point is from h to begin point

        // determine if a cycle
        ListNode *fast = head;
        ListNode *slow = head;
        bool isMeet = false;

        // if empty
        if (!head)
            return nullptr;

        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                isMeet = true;
                break;
            }
        } // while

        if (!isMeet)
        {
            return nullptr;
        }

        // now fast and slow are at the point they meet;
        while (head != slow)
        {
            head = head->next;
            slow = slow->next;
        } //while
        return head;
    }
};
// @lc code=end
