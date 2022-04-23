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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val == key)
        {
            // if root is a leaf
            if (!root->left && !root->right)
                return nullptr;
            // if root has single child
            else if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                // if root has both child
                // 1. find the first great element of the key
                // from the right sub tree
                // 2. replace it with the node to delete
                int nextGr = findMin(root->right);
                root->val = nextGr;
                root->right = deleteNode(root->right, nextGr);
            }
        }
        return root;
    }

    int findMin(TreeNode *root)
    {
        while (root->left)
            root = root->left;
        return root->val;
    }
};