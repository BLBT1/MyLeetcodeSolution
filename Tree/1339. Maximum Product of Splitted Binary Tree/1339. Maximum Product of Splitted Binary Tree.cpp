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
    long long sum;
    long long res = 0;

public:
    int maxProduct(TreeNode *root)
    {
        const int MOD = 1e9 + 7;
        this->sum = getSum(root);
        long long sum_ = getMaxProd(root);
        return res % MOD;
    }

    long long getMaxProd(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        long long leftSum = getMaxProd(root->left);
        long long rightSum = getMaxProd(root->right);
        long long temp = max(leftSum * (sum - leftSum), rightSum * (sum - rightSum));
        res = max(res, temp);

        return static_cast<long long>(root->val) + leftSum + rightSum;
    }

    long long getSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        long long leftSum = getSum(root->left);
        long long rightSum = getSum(root->right);
        return static_cast<long long>(root->val) + leftSum + rightSum;
    }
};