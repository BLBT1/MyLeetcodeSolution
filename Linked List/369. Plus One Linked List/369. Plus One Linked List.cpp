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
    ListNode *plusOne(ListNode *head)
    {
        head = reverse(head);
        int carry = 1;

        ListNode *node = head;
        ListNode *prev;
        while (carry != 0 && node != nullptr)
        {
            if (node == head)
                prev = head;
            else
                prev = prev->next;

            node->val += carry;
            carry = node->val / 10;
            node->val %= 10;
            node = node->next;
        }

        if (carry == 1)
        {
            ListNode *newNode = new ListNode(1);
            prev->next = newNode;
        }
        return reverse(head);
    }

    ListNode *reverse(ListNode *head)
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

// x<-y<-z
//    p
//       h
//       n