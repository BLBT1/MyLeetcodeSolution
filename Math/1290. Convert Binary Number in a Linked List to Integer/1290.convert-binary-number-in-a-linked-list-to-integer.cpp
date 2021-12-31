/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
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
    int getDecimalValue(ListNode *head)
    {
        int sum = 0;
        while (head != nullptr)
        {
            sum = sum << 1; // sum *= 2;
            if (head->val == 1)
            {
                sum += 1;
            }
            head = head->next;
        }
        return sum;
    }
};
// @lc code=end

// ex: 5 = 101
// 1          0         1
// 1*2^2  +   0*2^1  +  1 * 2 ^ 0 = 5
// 1
// 1*2+0 = 2
// 2*2+1 = 5