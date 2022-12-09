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

    bool isLeaf(TreeNode *node)
    {
        return node->left == nullptr && node->right == nullptr;
    }

    void getLeafSeq(vector<int> &seq, TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (isLeaf(root))
            seq.push_back(root->val);
        if (root->left)
            getLeafSeq(seq, root->left);
        if (root->right)
            getLeafSeq(seq, root->right);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leafSeq1;
        vector<int> leafSeq2;
        getLeafSeq(leafSeq1, root1);
        getLeafSeq(leafSeq2, root2);
        return leafSeq1 == leafSeq2;
    }
};