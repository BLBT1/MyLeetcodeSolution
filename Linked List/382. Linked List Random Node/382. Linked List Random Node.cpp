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
    ListNode *head;
    int len = 0;

public:
    Solution(ListNode *head)
    {
        this->head = head;
        ListNode *node = head;
        while (node)
        {
            len++;
            node = node->next;
        }
    }

    int getRandom()
    {
        int k = rand() % len;
        ListNode *node = head;
        while (k > 0)
        {
            node = node->next;
            --k;
        }
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */