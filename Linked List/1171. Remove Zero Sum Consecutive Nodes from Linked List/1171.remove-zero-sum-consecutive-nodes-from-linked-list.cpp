/*
 * @lc app=leetcode id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode dummyNode(0, head);
        unordered_map<int, ListNode *> Map;
        // first pass: find prefix sum of all nodes
        int presum = 0;
        ListNode *p = &dummyNode;
        while (p)
        {
            presum += p->val;
            Map[presum] = p;
            p = p->next;
        }

        // second pass: greedy jump
        p = &dummyNode;
        presum = 0;
        while (p)
        {
            presum += p->val;
            if (Map.find(presum) != Map.end())
            {
                p->next = Map[presum]->next;
            }
            p = p->next;
        }

        return dummyNode.next;
    }
};
// @lc code=end
