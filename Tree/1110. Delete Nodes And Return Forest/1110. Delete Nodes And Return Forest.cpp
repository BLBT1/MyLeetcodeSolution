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
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> td;
        for (auto i : to_delete)
            td.insert(i);

        vector<TreeNode *> res;
        TreeNode *new_root = helper(root, td, res);
        if (new_root)
            res.push_back(new_root);
        return res;
    }

    TreeNode *helper(TreeNode *root, unordered_set<int> &td, vector<TreeNode *> &res)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *leftNode = helper(root->left, td, res);
        TreeNode *rightNode = helper(root->right, td, res);

        if (td.find(root->val) == td.end())
        {
            root->left = leftNode;
            root->right = rightNode;
            return root;
        }
        else
        {
            if (leftNode)
                res.push_back(leftNode);
            if (rightNode)
                res.push_back(rightNode);
            return nullptr;
        }
    }
};