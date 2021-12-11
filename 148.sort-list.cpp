/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode *sortList(ListNode *head)
    {
        // only 0/1 element in the linked lists
        if (!head || !head->next)
            return head;

        //use fast-slow ptrs to find mid
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        } // while

        // break the list
        ListNode *slowNext = slow->next;
        slow->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(slowNext);
        return merge(left, right);
    }

    //* huahua's version of merge is better
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode dummy(0);
        ListNode *dummy_ptr = &dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                ListNode *next = left->next;
                left->next = nullptr;
                dummy_ptr->next = left;
                dummy_ptr = dummy_ptr->next;
                left = next;
            }
            else
            {
                ListNode *next = right->next;
                right->next = nullptr;
                dummy_ptr->next = right;
                dummy_ptr = dummy_ptr->next;
                right = next;
            } // end if
        }     // while

        while (right)
        {
            ListNode *next = right->next;
            right->next = nullptr;
            dummy_ptr->next = right;
            dummy_ptr = dummy_ptr->next;
            right = next;
        } // while
        while (left)
        {
            ListNode *next = left->next;
            left->next = nullptr;
            dummy_ptr->next = left;
            dummy_ptr = dummy_ptr->next;
            left = next;
        } //while

        return dummy.next;
    }
};
// @lc code=end
