This problem follows a common tree path problem pattern (lc 543, lc 298)
1. for each turnover, combine left child result and right child result
2. update global result
3. return only one side of result from each left child or right child (for each example, longest so far)

for this problem
for each turnover, we only care
1. what is largest increase so far and what is the largest decreasing so far
2. if left is increasing -> right need to be decreasing
   if left is decreasing -> right need to be increasing
so for each recursion, we need to return both longest increasing so far and longest decreasing so far

In this problem, we don't need to record the value of increasing/decreasing sequence because it is +1/-1,
so we can get this from the node value already

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
    int res = 0;
public:
    int longestConsecutive(TreeNode* root) {
        helper(root);
        return res;
    }

    // return {longest increasing, longest decreasing}
    pair<int, int> helper(TreeNode *curr){
        if(curr == nullptr) return {};

        pair<int, int> leftRes = helper(curr->left);
        pair<int, int> rightRes = helper(curr->right);

        int dec = 1, inc = 1; // both set to 1 for current node

        if(curr->left){
            if(curr->val - curr->left->val == 1) {
                // for decreasing
                dec = leftRes.second+1;
            }
            if(curr->val - curr->left-> val == -1){
                // for increasing
                inc = leftRes.first+1;
            }
            // else keep as 1 for self node
        }

        if(curr->right){
            if(curr->val - curr->right->val == 1) {
                // for decreasing, need to also compare with res from left
                dec = max(rightRes.second+1, dec);
            }
            if(curr->val - curr->right->val == -1){
                // for increasing, need to also compare with res from left
                inc = max(rightRes.first+1, inc);
            }
        }

        // left+right (-1 because both increasing and decresing count self)
        res = max(res, inc+dec-1);
        
        return {inc, dec};
    }
};

// This problem follows a common tree path problem pattern (lc 543, lc 298)
// 1. for each turnover, combine left child result and right child result
// 2. update global result
// 3. return only one side of result from each left child or right child (for each example, longest so far)

// for this problem
// for each turnover, we only care
// 1. what is largest increase so far and what is the largest decreasing so far
// 2. if left is increasing -> right need to be decreasing
//    if left is decreasing -> right need to be increasing
// so for each recursion, we need to return both longest increasing so far and longest decreasing so far

// In this problem, we don't need to record the value of increasing/decreasing sequence because it is +1/-1,
// so we can get this from the node value already
```

