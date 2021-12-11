/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        //maybe define 2 ptrs
        ListNode *begin = head, *end = head;

        // find the length
        int length = 0;
        int i = 0;

        for (ListNode *ptr = head; ptr; ptr = ptr->next, ++length,++i){
            if (!ptr->next)
            {
                end = ptr;
            }
        }

        if (length == 0 ||length == 1)
           return head;
        int Rot = k % length;

        for (int i = 0; i < length - Rot - 1; ++i)
        {
            begin = begin->next;
        } // for

        end->next = head;
        head = begin->next;
        begin->next = nullptr;

        return head;
    }
};
// @lc code=end
