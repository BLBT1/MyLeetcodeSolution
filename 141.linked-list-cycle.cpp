/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next)
        {
            // 一定要先移动后检查，因为初始一致
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }

        return false;
    }
};
// @lc code=end
