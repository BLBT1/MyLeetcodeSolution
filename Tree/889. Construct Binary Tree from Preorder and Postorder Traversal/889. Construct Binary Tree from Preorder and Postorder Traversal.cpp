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
    unordered_map<int, int> postmap;

public:
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        for (int i = 0; i < postorder.size(); ++i)
            postmap[postorder[i]] = i;

        return helper(preorder, postorder, 0, preorder.size() - 1,
                      0, postorder.size() - 1);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &postorder,
                     int prebeg, int preend, int postbeg, int postend)
    {
        if (prebeg > preend || postbeg > postend)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[prebeg]);

        if (prebeg + 1 <= preend)
        {
            int leftTreeLen = postmap[preorder[prebeg + 1]] - postbeg;
            root->left = helper(preorder, postorder, prebeg + 1, prebeg + 1 + leftTreeLen, postbeg, postbeg + leftTreeLen);
            root->right = helper(preorder, postorder, prebeg + 1 + leftTreeLen + 1, preend, postbeg + leftTreeLen + 1, postend - 1);
        }
        return root;
    }
};