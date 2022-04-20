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
class BSTIterator
{
    stack<TreeNode *> s;
    TreeNode *node;

public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        node = root;
    }

    int next()
    {
        while (node)
        {
            s.push(node);
            node = node->left;
        }
        node = s.top();
        int res = node->val;
        s.pop();
        node = node->right;
        return res;
    }

    bool hasNext()
    {
        return node != nullptr || !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */