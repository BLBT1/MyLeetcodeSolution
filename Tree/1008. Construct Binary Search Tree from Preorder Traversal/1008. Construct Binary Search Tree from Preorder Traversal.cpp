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
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        queue<TreeNode *> q;
        for (int &i : preorder)
        {
            q.push(new TreeNode(i));
        }

        return dfs(q, INT_MIN, INT_MAX);
    }

    TreeNode *dfs(queue<TreeNode *> &q, int lower, int upper)
    {
        if (q.empty())
            return nullptr;

        TreeNode *root = q.front();
        if (root->val < lower || root->val > upper)
            return nullptr; // out of bound, need to start a new tree
        q.pop();
        root->left = dfs(q, lower, root->val);
        root->right = dfs(q, root->val, upper);
        return root;
    }
};