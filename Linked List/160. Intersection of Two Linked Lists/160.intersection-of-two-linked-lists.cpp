/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while (p1 != nullptr && p2 != nullptr && p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;

            if (p1 == p2)
                return p1;

            if (p1 == nullptr)
                p1 = headB;
            if (p2 == nullptr)
                p2 = headA;
        }
        return p1;
    }
};
// @lc code=end
