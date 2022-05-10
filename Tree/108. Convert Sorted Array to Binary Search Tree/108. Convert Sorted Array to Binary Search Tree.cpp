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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int beg, int end)
    {
        if (beg > end)
            return nullptr;
        int mid = beg + (end - beg) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, beg, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }
};