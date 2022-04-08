/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // divide into three pieces
        // a: before left
        // b: middle part need to be reversed
        // c: after right

        // because it is possible that the left == 0, right == nullptr
        // to make each part meaningful, we can use a nullptr
        ListNode dummyNode = ListNode(0, head);
        ListNode *dummy = &dummyNode;

        // break into 3 pieces
        // must break the right piece first, otherwise we cannot reach right after break the left
        ListNode *ptr = dummy;
        for (int i = 0; i < right; ++i)
        {
            ptr = ptr->next;
        }
        ListNode *c = ptr->next;
        ptr->next = nullptr;

        // break the left;
        ptr = dummy;
        for (int i = 0; i < left - 1; ++i)
        {
            ptr = ptr->next;
        }
        ListNode *b = ptr->next;
        ptr->next = nullptr;

        // return the middle part (b part)
        b = reverseListedList(b);

        // connect three pieces back
        ptr = dummy;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = b;
        while (ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = c;

        return dummy->next;
    }

    ListNode *reverseListedList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *next;
        while (head != nullptr)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
// @lc code=end
