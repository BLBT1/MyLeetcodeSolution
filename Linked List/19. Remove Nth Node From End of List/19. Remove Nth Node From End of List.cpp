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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummyNode(0, head);
        int cnt = 0;
        ListNode *p1 = &dummyNode;
        ListNode *p2 = &dummyNode;
        while (p1 != nullptr)
        {
            if (cnt > n)
            {
                p2 = p2->next;
            }
            cnt++;
            p1 = p1->next;
        }
        ListNode *nxt = nullptr;
        if (p2->next != nullptr)
        {
            nxt = p2->next->next;
        }
        p2->next = nxt;
        return dummyNode.next;
    }
};