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
    vector<vector<int>> res;

public:
    vector<vector<int>> findLeaves(TreeNode *root)
    {
        getHeight(root);
        return res;
    }
    int getHeight(TreeNode *root)
    {
        if (!root)
            return -1;

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        int currHeight = max(lh, rh) + 1;

        if (res.size() == currHeight)
            res.push_back({});

        res[currHeight].push_back(root->val);
        return currHeight;
    }
};