/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummyNode(0);
        ListNode *dummy = &dummyNode;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        for (auto &head : lists)
        {
            if (head != nullptr)
                pq.push(head);
        }

        while (!pq.empty())
        {
            // add to list
            ListNode *nxt = pq.top();
            pq.pop();
            dummy->next = nxt;
            dummy = dummy->next;

            if (nxt->next != nullptr)
                pq.push(nxt->next);
        }
        return dummyNode.next;
    }
};
// @lc code=end

// 1,4,5
// 1,3,4
// 2,6