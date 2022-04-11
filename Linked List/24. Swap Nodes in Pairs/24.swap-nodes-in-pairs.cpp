/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode dummyNode(0, head);
        ListNode *dummy = &dummyNode;
        ListNode *prev = &dummyNode;
        ListNode *first = head;
        ListNode *second = nullptr;
        if (first != nullptr)
            second = first->next;
        while (second != nullptr)
        {
            ListNode *nxt = second->next;
            prev->next = second;
            second->next = first;
            first->next = nxt;
            prev = first;
            first = nxt;
            if (first != nullptr)
                second = first->next;
            else
                second = nullptr;
        }
        return dummy->next;
    }
};
// d -> 1->2->3->4
// p
//      f
//         s
//            n
// @lc code=end
