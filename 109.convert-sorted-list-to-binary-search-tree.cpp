/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
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
        //* recurseively insert to the mid point to the tree
        if (!head)
            return nullptr;
        return toBstHelper(head, nullptr);
    }

    // [begin,end)
    TreeNode *toBstHelper(ListNode *begin, ListNode *end)
    {

        // base case
        if (begin == end)
            return nullptr;

        //* find the mid point
        ListNode *slow = begin;
        ListNode *fast = begin;
        while (fast->next != end && fast->next->next != end)
        {
            fast = fast->next->next;
            // temp = slow; // record the node before slow
            slow = slow->next;
        } //while

        // slow now is at the mid point
        TreeNode *root = new TreeNode(slow->val);

        root->left = toBstHelper(begin, slow);
        root->right = toBstHelper(slow->next, end);

        return root;
    }
};
// @lc code=end
