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
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // use postorder traversal to pass info from leaves to ancestors
        if (root == nullptr)
            return nullptr;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (root == p || root == q)
            return root;
        if (left != nullptr && right != nullptr)
            return root;
        else if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;
        else
            return nullptr;
    }
}; /**
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
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // use postorder traversal to pass info from leaves to ancestors
        if (root == nullptr)
            return nullptr;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (root == p || root == q)
            return root;
        if (left != nullptr && right != nullptr)
            return root;
        else if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;
        else
            return nullptr;
    }
};