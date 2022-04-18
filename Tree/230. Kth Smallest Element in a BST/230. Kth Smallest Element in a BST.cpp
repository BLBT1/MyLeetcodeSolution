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
    int cnt = 1;
    int res;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        res = 0;
        inorder(root, k);
        return res;
    }

    void inorder(TreeNode *root, int k)
    {
        if (root == nullptr)
            return;
        inorder(root->left, k);

        if (cnt == k)
        {
            res = root->val;
        }
        cnt++;
        inorder(root->right, k);
    }
};