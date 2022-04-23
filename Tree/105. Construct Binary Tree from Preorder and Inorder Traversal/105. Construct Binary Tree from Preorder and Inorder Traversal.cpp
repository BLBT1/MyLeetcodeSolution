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
    unordered_map<int, int> inorder_map;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            inorder_map[inorder[i]] = i;

        return helper(preorder, inorder, 0, 0, inorder.size() - 1);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder,
                     int root, int inorder_beg, int inorder_end)
    {
        if (root >= preorder.size() || inorder_beg > inorder_end)
            return nullptr;

        TreeNode *rootNode = new TreeNode(preorder[root]);

        int inorder_root = inorder_map[preorder[root]];
        rootNode->left = helper(preorder, inorder, root + 1, inorder_beg, inorder_root - 1);
        rootNode->right = helper(preorder, inorder, root + inorder_root - inorder_beg + 1, inorder_root + 1, inorder_end);

        return rootNode;
    }
};