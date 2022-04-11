/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummyNode(0, head);
        ListNode *prev = &dummyNode;
        while (prev->next && prev->next->next)
        {
            if (prev->next->val == prev->next->next->val)
            {
                ListNode *p = prev->next;
                while (p->next != nullptr && p->val == p->next->val)
                {
                    p = p->next;
                }
                prev->next = p->next;
            }
            else
            {
                prev = prev->next;
            }
        }
        return dummyNode.next;
    }
};
// @lc code=end
