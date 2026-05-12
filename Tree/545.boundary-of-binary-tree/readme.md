```c++
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
class Solution {
    vector<int> res;
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // single node
        if(!root->left && !root->right)
            return {root->val};

        res.push_back(root->val);
        addLeft(root->left);
        addLeaves(root);
        addRight(root->right);

        return res;
    }

    bool isLeaf(TreeNode *curr){
        return !curr->left && !curr->right;
    }

    void addLeft(TreeNode *curr){
        if(!curr || isLeaf(curr))
            return;

        res.push_back(curr->val);
        
        if(curr->left)
            addLeft(curr->left);
        else // base on defination, right no left child, take right
            addLeft(curr->right);
    }

    // reverse order
    void addRight(TreeNode *curr){
        if(!curr || isLeaf(curr))
            return;
        
        if(curr->right)
            addRight(curr->right);
        else
            addRight(curr->left);
        
        res.push_back(curr->val);
    }

    void addLeaves(TreeNode *curr){
        if(!curr) return;
        
        if(isLeaf(curr)) res.push_back(curr->val);

        addLeaves(curr->left);
        addLeaves(curr->right);
    }
};

// root + left boundary (in order) + leaf nodes + right boundary (reverse order)
```

