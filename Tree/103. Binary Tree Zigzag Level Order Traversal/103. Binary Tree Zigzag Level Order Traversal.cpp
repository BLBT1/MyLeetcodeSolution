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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        if (root)
            q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int len = q.size();
            vector<int> level_nodes;
            for (int i = 0; i < len; ++i)
            {
                auto x = q.front();
                q.pop();
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
                level_nodes.push_back(x->val);
            }
            if (level % 2 == 1)
                reverse(level_nodes.begin(), level_nodes.end());
            level++;
            res.push_back(level_nodes);
        }
        return res;
    }
};