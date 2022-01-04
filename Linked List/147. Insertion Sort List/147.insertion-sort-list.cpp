/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy(-1, head);
        ListNode *curr = head;
        ListNode *prev = &dummy;
        ListNode *temp = head;
        while (curr != nullptr && curr->next != nullptr)
        {
            if (curr->val > curr->next->val)
            {
                // remove the curr->next
                temp = curr->next;
                curr->next = curr->next->next;

                // find the right position to insert
                while (temp->val > prev->next->val)
                {
                    prev = prev->next;
                }

                temp->next = prev->next;
                prev->next = temp;

                prev = &dummy;
            }
            else
            {
                curr = curr->next;
            }

        } //while

        return dummy.next;
    }
};

// @lc code=end
