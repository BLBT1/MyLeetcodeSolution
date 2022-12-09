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
    int diff = INT_MIN;

public:
    int maxAncestorDiff(TreeNode *root)
    {
        findMaxDiff(root, 0, 100000);
        return diff;
    }

    void findMaxDiff(TreeNode *node, int mx, int mn)
    {
        if (node == nullptr)
            return;

        mx = max(mx, node->val);
        mn = min(mn, node->val);
        int mxDiff = abs(mx - node->val);
        int mnDiff = abs(mn - node->val);

        diff = max(max(mxDiff, mnDiff), diff);

        findMaxDiff(node->left, mx, mn);
        findMaxDiff(node->right, mx, mn);
    }
};