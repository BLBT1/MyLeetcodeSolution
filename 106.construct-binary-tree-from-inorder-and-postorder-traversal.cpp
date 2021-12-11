/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
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
    unordered_map<int, int> inorder_map; //{val, idx}
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // make a map for inorder
        const int n = inorder.size();
        for (int i = 0; i < inorder.size(); ++i)
        {
            inorder_map[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int inSt, int inEnd, int postSt, int postEnd)
    {
        // base case
        if (inSt > inEnd)
            return nullptr;

        // int the postorder, the last node int range is the root
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);
        int pos = inorder_map[rootVal];

        root->left = helper(inorder, postorder, inSt, pos - 1, postSt, postSt + pos - 1 - inSt);
        root->right = helper(inorder, postorder, pos + 1, inEnd, postSt + pos - inSt, postEnd - 1);

        return root;
    }
};
// @lc code=end
