/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<ListNode *> heads;
        ListNode dummyNode(0, head);
        ListNode *dummy = &dummyNode;
        bool flag = false; // if need to reverse the last group

        // break list into group
        while (head != nullptr)
        {
            heads.push_back(head);

            for (int i = 0; i < k - 1; i++)
            {
                if (head->next)
                    head = head->next;
                else
                    flag = true;
            }

            ListNode *nxt = head->next;
            head->next = nullptr;
            head = nxt;
        }

        for (int j = 0; j < heads.size(); ++j)
        {
            if (!flag || j != heads.size() - 1)
                heads[j] = reverseList(heads[j]);
        }

        for (int j = 0; j < heads.size(); ++j)
        {
            if (j == 0)
            {
                dummy->next = heads[j];
                while (dummy->next != nullptr)
                    dummy = dummy->next;
            }
            else
            {
                dummy->next = heads[j];
                while (dummy->next != nullptr)
                    dummy = dummy->next;
            }
        }
        return dummyNode.next;
    }

    ListNode *reverseList(ListNode *head)
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
