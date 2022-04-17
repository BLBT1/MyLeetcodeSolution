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
    bool isCompleteTree(TreeNode *root)
    {
        int numNodes = countNodes(root);
        return dfs(root, 0, numNodes);
    }

    bool dfs(TreeNode *root, int idx, int numNodes)
    {
        if (!root)
            return true;
        if (idx >= numNodes)
            return false;
        return dfs(root->left, idx * 2 + 1, numNodes) && dfs(root->right, idx * 2 + 2, numNodes);
    }

    int countNodes(TreeNode *root)
    {
        if (root == 0)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};