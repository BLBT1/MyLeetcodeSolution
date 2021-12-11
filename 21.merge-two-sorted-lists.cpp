/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0, nullptr);
        ListNode *dumPtr = &dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                ListNode *tmp = l1->next;
                dumPtr->next = l1;
                dumPtr = dumPtr->next;
                l1 = tmp;
            }
            else
            {
                ListNode *tmp = l2->next;
                dumPtr->next = l2;
                dumPtr = dumPtr->next;
                l2 = tmp;
            }
        }

        if (l1)
        {
            dumPtr->next = l1;
        }

        if (l2)
        {
            dumPtr->next = l2;
        }

        return dummy.next;
    }
};
// @lc code=end
