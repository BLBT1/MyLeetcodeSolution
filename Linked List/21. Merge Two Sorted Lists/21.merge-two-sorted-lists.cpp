/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummyNode(0);
        ListNode *dummy = &dummyNode;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                dummy->next = list1;
                dummy = dummy->next;
                list1 = list1->next;
            }
            else
            {
                dummy->next = list2;
                dummy = dummy->next;
                list2 = list2->next;
            }
        }
        while (list1)
        {
            dummy->next = list1;
            dummy = dummy->next;
            list1 = list1->next;
        }
        while (list2)
        {
            dummy->next = list2;
            dummy = dummy->next;
            list2 = list2->next;
        }
        return dummyNode.next;
    }
};
// @lc code=end
