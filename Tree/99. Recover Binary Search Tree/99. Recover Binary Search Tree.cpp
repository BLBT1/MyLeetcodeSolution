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
    TreeNode *prev;
    TreeNode *first;
    TreeNode *second;

public:
    void recoverTree(TreeNode *root)
    {
        first = nullptr;
        second = nullptr;
        // bst + indorder -> sorted
        prev = new TreeNode(INT_MIN);
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    // inorder to record two swapped nodes
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);

        // do something with the curr node
        if (prev->val > root->val)
        {
            if (first == nullptr)
            {
                first = prev;
                second = root;
                prev = root;
            }
            else
            {
                second = root;
                return;
            }
        }
        else
        {
            prev = root;
        }

        inorder(root->right);
    }
};