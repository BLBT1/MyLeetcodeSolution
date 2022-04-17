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
        queue<TreeNode *> q;
        q.push(root);
        while (q.front() != nullptr)
        {
            int len = q.size();
            for (int i = 0; i < q.size(); ++i)
            {
                auto x = q.front();
                if (x == nullptr)
                    break;
                q.pop();
                q.push(x->left);
                q.push(x->right);
            }
        }

        while (!q.empty())
        {
            auto x = q.front();
            if (x != nullptr)
                return false;
            q.pop();
        }

        return true;
    }
};