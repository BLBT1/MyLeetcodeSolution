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
    int res = 0;
    double minDiff = std::numeric_limits<double>::max();

public:
    int closestValue(TreeNode *root, double target)
    {
        this->res = root->val;
        minDiff = abs((double)root->val - target);
        preOrder(root, target);
        return res;
    }

    void preOrder(TreeNode *root, double target)
    {
        if (!root)
            return;
        double currDiff = abs((double)root->val - target);
        if (currDiff < minDiff)
        {
            minDiff = currDiff;
            res = root->val;
        }

        preOrder(root->left, target);
        preOrder(root->right, target);
    }
};
