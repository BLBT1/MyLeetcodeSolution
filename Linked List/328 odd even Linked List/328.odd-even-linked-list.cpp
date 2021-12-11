/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode dummy;
        ListNode *dummyPtr = &dummy;
        ListNode *curr = head->next;
        ListNode *prev = head;
        int cnt = 0;
        while (curr)
        {
            if (cnt % 2 == 0)
            {
                prev->next = curr->next;
                dummyPtr->next = curr;
                curr = curr->next;
                dummyPtr = dummyPtr->next;
                dummyPtr->next = nullptr;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
            cnt++;
        }

        prev->next = dummy.next;
        return head;
    }
};
// @lc code=end
