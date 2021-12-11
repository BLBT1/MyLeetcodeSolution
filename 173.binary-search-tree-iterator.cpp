/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator
{
    stack<TreeNode *> s;

public:
    BSTIterator(TreeNode *root)
    {
        // from root, push all the left node into the stack
        TreeNode *node = root;
        while (node)
        {
            s.push(node);
            node = node->left;
        } //while
    }

    int next()
    {
        int val = s.top()->val;
        TreeNode *node = s.top()->right;
        s.pop();

        while (node)
        {
            s.push(node);
            node = node->left;
        } //while

        return val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
