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
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        bool isValid = true;
        if (root->right && minElt(root->right) <= root->val)
            isValid = false;
        if (root->left && maxElt(root->left) >= root->val)
            isValid = false;

        return isValidBST(root->left) && isValidBST(root->right) && isValid;
    }

    int maxElt(TreeNode *root)
    {
        while (root->right)
            root = root->right;
        return root->val;
    }
    int minElt(TreeNode *root)
    {
        while (root->left)
            root = root->left;
        return root->val;
    }
};

//         5
//     4       6
// null  null 3  7
