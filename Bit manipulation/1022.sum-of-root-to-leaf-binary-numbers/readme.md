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
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        
        int sum = 0;
        for(auto n: res){
            cout << n << endl;
            sum+=n;
        }
    

        return sum;
    }

    void dfs(TreeNode* curr, int currNum){
        if(curr -> left == nullptr && curr->right == nullptr){
            currNum = (currNum << 1) | curr->val;
            res.push_back(currNum);
            currNum = currNum >> 1;
            return;
        }
        
        // append to last bit
        currNum = (currNum << 1) | curr->val;
        
        if (curr->left)
            dfs(curr->left, currNum);
        
        if(curr -> right)
            dfs(curr->right, currNum);

        // remove from the last bit
        currNum = currNum >> 1;
    }
};
```