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
    int maxAncestorDiff(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = maxAncestorDiff(root->left);
        int right = maxAncestorDiff(root->right);
        int currMaxDiff = maxDiff(root->val, root);

        return max(max(left, right), currMaxDiff);
    }

    int maxDiff(int val, TreeNode *curr)
    {
        if (curr == nullptr)
            return 0;

        int leftMax = maxDiff(val, curr->left);
        int rightMax = maxDiff(val, curr->right);
        int currDiff = int(abs(curr->val - val));
        return max(max(leftMax, rightMax), currDiff);
    }
};

// O(N^2)