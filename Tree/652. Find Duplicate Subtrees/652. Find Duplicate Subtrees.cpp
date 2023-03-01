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
    unordered_map<string, int> key2cnt;
    vector<TreeNode *> res;

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        serialize(root);
        return res;
    }
    string serialize(TreeNode *node)
    {
        if (node == nullptr)
            return "";
        string key = to_string(node->val) + "#(" + serialize(node->left) + ")#(" + serialize(node->right) + ")";
        if (key2cnt.find(key) == key2cnt.end())
        {
            key2cnt[key] = 1;
        }
        else
        {
            key2cnt[key] += 1;
            if (key2cnt[key] == 2)
                res.push_back(node);
        }
        return key;
    }
};

// one thing need to keep in mind is that a serialized preorder traversal of a tree is unique for each tree
// we can use serialized of each subtree to compare
// we can use a map {serialized, cnt}
// string key = node->val + # + serialize(node->left) + # serialize(node->right)