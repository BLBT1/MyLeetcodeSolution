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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> res;
        if (!root)
            return {};
        while (!q.empty())
        {
            vector<int> level;
            int len = q.size();
            level.reserve(len);
            for (int i = 0; i < len; ++i)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                level.push_back(curr->val);
            } // for
            res.push_back(level);
        } // while
        reverse(res.begin(), res.end());
        return res;
    }
};