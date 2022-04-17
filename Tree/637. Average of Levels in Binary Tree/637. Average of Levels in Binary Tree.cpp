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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<double> res;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int len = q.size();
            double sum = 0;
            for (int i = 0; i < len; ++i)
            {
                auto x = q.front();
                q.pop();
                sum += x->val;
                if (x->left)
                    q.push(x->left);
                if (x->right)
                    q.push(x->right);
            }
            res.push_back(sum / double(len));
        }
        return res;
    }
};