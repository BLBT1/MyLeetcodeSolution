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
    unordered_map<int, int> in_map; // {val, idx}
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            in_map[inorder[i]] = i;

        return helper(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *helper(vector<int> &inorder, vector<int> &postorder,
                     int root, int in_beg, int in_end)
    {
        if (root < 0 || in_beg > in_end)
            return nullptr;
        TreeNode *rootNode = new TreeNode(postorder[root]);

        int in_root = in_map[postorder[root]];

        rootNode->left = helper(inorder, postorder, root - (in_end - in_root) - 1, in_beg, in_root - 1);
        rootNode->right = helper(inorder, postorder, root - 1, in_root + 1, in_end);

        return rootNode;
    }
};
