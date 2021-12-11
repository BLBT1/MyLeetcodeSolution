/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
        // idea: use stack to reverse the linked list
        stack<int> s1;
        stack<int> s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        ListNode *head = nullptr;
        int sum = 0;
        int carry = 0;

        while (!s1.empty() || !s2.empty() || carry)
        {
            // sum == carry aleady
            sum += s1.empty() ? 0 : s1.top();
            sum += s2.empty() ? 0 : s2.top();

            // pop from the stack
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
            ListNode *n = new ListNode(sum % 10);
            carry = sum /= 10;

            // insert to the front of the result list
            n->next = head;
            head = n;
        }
        return head;
    } //fxn
};
// @lc code=end
