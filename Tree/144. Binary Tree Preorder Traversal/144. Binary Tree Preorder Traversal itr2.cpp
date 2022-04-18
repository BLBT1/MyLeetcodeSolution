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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> nodes;
        if (root)
            nodes.push(root);
        while (!nodes.empty())
        {
            auto x = nodes.top();
            nodes.pop();
            res.push_back(x->val);
            if (x->right)
                nodes.push(x->right);
            if (x->left)
                nodes.push(x->left);
        }
        return res;
    }
};