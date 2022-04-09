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
    ListNode *reverseEvenLengthGroups(ListNode *head)
    {
        // each group has one more node than the previous group
        vector<ListNode *> heads;
        vector<int> lens; // record length of each group
        ListNode dummyNode(0, head);
        ListNode *dummy = &dummyNode;
        int k = 1;
        while (head != nullptr)
        {
            heads.push_back(head);
            int cnt = 1;
            for (int i = 0; i < k - 1; ++i)
            {
                if (head->next)
                {
                    cnt++;
                    head = head->next;
                }
                else
                    break;
            }
            // break the link
            lens.push_back(cnt);
            ListNode *nxt = head->next;
            head->next = nullptr;
            head = nxt;
            k = k + 1;
        }

        for (int i = 0; i < heads.size(); ++i)
        {
            if (lens[i] % 2 == 0)
                heads[i] = reverseList(heads[i]);
        }

        // reassamble
        for (int j = 0; j < heads.size(); ++j)
        {
            dummy->next = heads[j];
            while (dummy->next != nullptr)
                dummy = dummy->next;
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