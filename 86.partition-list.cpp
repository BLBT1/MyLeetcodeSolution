/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        //* idea: split into two ll
        //* one less and one greater
        //* append them at the end

        //* use dummy head in LL
        ListNode h1(0);
        ListNode h2(0);
        ListNode *p = &h1;
        ListNode *q = &h2;

        while (head)
        {
            if (head->val < x)
            {
                p->next = head;
                p = p->next;
            } //if
            else
            {
                q->next = head;
                q = q->next;
            } //else
            head = head->next;
        } //while
        p->next = h2.next;
        q->next = nullptr;
        return h1.next;
    }
};
// @lc code=end
