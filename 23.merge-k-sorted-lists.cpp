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
class Solution
{
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            if (a->val != b->val)
            {
                return a->val > b->val;
            }
            return true;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy(-1, nullptr);
        ListNode *dumPtr = &dummy;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

        // add all the top nodes into the list
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
            {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty())
        {
            ListNode *min = pq.top();
            pq.pop();
            if (min->next)
                pq.push(min->next);
            min->next = nullptr;
            dumPtr->next = min;
            dumPtr = dumPtr->next;
        } //while

        return dummy.next;
    }
};
// @lc code=end

// 1,4,5
// 1,3,4
// 2,6