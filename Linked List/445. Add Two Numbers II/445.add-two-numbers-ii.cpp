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
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        return reverseList(addTwoReveresed(l1, l2));
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *next;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    ListNode *addTwoReveresed(ListNode *l1, ListNode *l2)
    {
        // dummy head for res
        ListNode dummyNode(0);
        ListNode *dummy = &dummyNode;

        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = 0;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;
        }
        return dummyNode.next;
    }
};
// @lc code=end
