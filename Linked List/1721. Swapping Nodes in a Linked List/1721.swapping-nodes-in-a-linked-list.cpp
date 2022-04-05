/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
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
    ListNode *swapNodes(ListNode *head, int k)
    {
        int cnt = 1; // start from idx 1
        ListNode *curr = head;
        ListNode *l = head;
        ListNode *r = head;
        while (curr != nullptr)
        {
            if (cnt < k)
            {
                l = l->next;
            }
            if (cnt > k)
            {
                r = r->next;
            }
            curr = curr->next;
            cnt++;
        }

        // exchange the node of l and r
        int temp = l->val;
        l->val = r->val;
        r->val = temp;
        return head;
    }
};
// @lc code=end
