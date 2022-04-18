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
    vector<vector<int>> verticalOrder(TreeNode *root)
    {
        // use root position as 0 col
        map<int, vector<int>> ans;
        // use level order traversal
        queue<pair<int, TreeNode *>> q;
        if (root)
            q.push({0, root});
        while (!q.empty())
        {
            auto pair = q.front();
            q.pop();
            int pos = pair.first;
            TreeNode *node = pair.second;
            ans[pos].push_back(node->val);

            if (node->left)
                q.push({pos - 1, node->left});
            if (node->right)
                q.push({pos + 1, node->right});
        }
        vector<vector<int>> res;
        for (auto &p : ans)
            res.push_back(p.second);
        return res;
    }
};