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
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy(-1, nullptr);
        ListNode *dumPtr = &dummy;

        while (hasVal(lists))
        {
            int minNode = findMinNode(lists);
            cout << minNode << endl;
            ListNode *temp = lists[minNode]->next;
            lists[minNode]->next = nullptr;
            dumPtr->next = lists[minNode];
            dumPtr = dumPtr->next;
            lists[minNode] = temp;
        }

        return dummy.next;
    }

    bool hasVal(vector<ListNode *> &lists)
    {
        for (auto &node : lists)
        {
            if (node)
                return true;
        }
        return false;
    }

    int findMinNode(vector<ListNode *> lists)
    {
        ListNode *res = nullptr;
        int idx = 0;
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
            {
                res = lists[i];
                idx = i;
                break;
            }
        }

        for (int j = idx; j < lists.size(); ++j)
        {
            if (lists[j] && lists[j]->val < res->val)
            {
                res = lists[j];
                idx = j;
            }
        }

        return idx;
    }
};
// @lc code=end

// 1,4,5
// 1,3,4
// 2,6