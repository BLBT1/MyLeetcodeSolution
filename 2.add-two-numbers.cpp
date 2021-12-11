/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // should not assume that the num can be represented by 64 bit
        int carry = 0;    // either 1/0
        ListNode temp(0); // a temp node, in the stack
        ListNode *res = &temp;
        int sum = 0;
        while (l1 || l2 || carry)
        {
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            res->next = new ListNode(sum % 10);
            res = res->next;
            carry = sum /= 10;
        } //while
        return temp.next;
    }
};
// @lc code=end
