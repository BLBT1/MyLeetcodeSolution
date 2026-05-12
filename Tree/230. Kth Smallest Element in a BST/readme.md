Most important insight --> inorder traversal on BST will traverse in sorting order

For kth largest, we just go with right, curr, left


### recursive
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
    int seen = 0;
    int res = -1;
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }

    void inorder(TreeNode* curr, int k){
        if(curr == nullptr) return;

        // left
        inorder(curr->left, k);

        // curr
        if(seen == k-1)
            res = curr->val;

        seen +=1;

        inorder(curr->right, k);
    }
};

// inorder traversal will traverse the tree in the order of being sorted
// if the question is kth largers element, we should traverse in order of right, curr, left 
```

### iterative

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
public:
    int kthSmallest(TreeNode* root, int k) {
        // benefit of using iterative implementation is that it does not need to alway traverase the entire tree
        stack<TreeNode*> s;
        TreeNode* curr = root;
        int res = 0;
        int count = 0;
        while(true){
            while(curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();

            count += 1;
            if(count == k)
                return curr->val;

            curr = curr->right;
        }
        return -1;
    }
};
```

