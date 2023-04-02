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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return helper(head, nullptr);
    }

    // [begin, end)
    TreeNode *helper(ListNode *begin, ListNode *end)
    {
        if (begin == end)
            return nullptr;
        // find mid point
        ListNode *slow = begin;
        ListNode *fast = begin;
        while (fast != end && fast->next != end)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        TreeNode *mid = new TreeNode(slow->val);
        mid->left = helper(begin, slow);
        mid->right = helper(slow->next, end);
        return mid;
    }
};

// X -> X -> X -> X
//           s
//                 f