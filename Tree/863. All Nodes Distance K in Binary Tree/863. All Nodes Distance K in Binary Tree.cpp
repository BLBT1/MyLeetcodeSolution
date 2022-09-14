/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
    unordered_map<TreeNode *, vector<TreeNode *>> adj;
    unordered_set<int> visited;

public:
    vector<int> distanceK(TreeNode *root,
                          TreeNode *tar,
                          int k)
    {

        // dfs to map the map, then bfs to find distance
        dfs(root);

        queue<TreeNode *> q;
        q.push(tar);
        visited.insert(tar->val);

        int dist = 0;
        vector<int> res;

        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto curr = q.front();
                q.pop();

                if (k == dist)
                    res.push_back(curr->val);

                for (auto next : adj[curr])
                {
                    if (visited.find(next->val) != visited.end())
                        continue;
                    visited.insert(next->val);
                    q.push(next);
                }
            }

            if (dist == k)
                return res;

            dist += 1;
        }

        return {};
    }

    void dfs(TreeNode *node)
    {
        if (node == nullptr)
            return;

        if (node->left)
        {
            adj[node].push_back(node->left);
            adj[node->left].push_back(node);
            dfs(node->left);
        }

        if (node->right)
        {
            adj[node].push_back(node->right);
            adj[node->right].push_back(node);
            dfs(node->right);
        }
    }
};