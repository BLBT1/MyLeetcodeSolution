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
    string getDirections(TreeNode *root,
                         int start,
                         int dest)
    {
        vector<int> nums1;
        vector<int> nums2;
        string path1;
        string path2;

        dfs(root, nums1, path1, start);
        dfs(root, nums2, path2, dest);

        // find LCA
        int k = 0;
        while (k < nums1.size() && k < nums2.size() && nums1[k] == nums2[k])
        {
            ++k;
        }

        for (int i = k; i < path1.size(); ++i)
        {
            path1[i] = 'U';
        }

        return path1.substr(k) + path2.substr(k);
    }

    bool dfs(TreeNode *node, vector<int> &nums, string &s, int tar)
    {
        if (node == nullptr)
            return false;
        if (node->val == tar)
            return true;

        if (node->left)
        {
            nums.push_back(node->left->val);
            s.push_back('L');
            if (dfs(node->left, nums, s, tar))
                return true;
            nums.pop_back();
            s.pop_back();
        }
        if (node->right)
        {
            nums.push_back(node->right->val);
            s.push_back('R');
            if (dfs(node->right, nums, s, tar))
                return true;
            nums.pop_back();
            s.pop_back();
        }

        return false;
    }
};