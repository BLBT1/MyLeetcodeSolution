
The key of this problem is how to sort values in each col.
We could store row as part of cols value, and sort based on row.

``` c++
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

// the key of this problem is how to sort values in each col.
// We could store row as part of cols value, and sort based on row.
class Solution {
    map<int, vector<pair<int, int>>> cols; // col -> [(row, val), ...]

    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first != b.first){
            return a.first < b.first;
        }
        return a.second < b.second;
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        pair<int, int> start = {0,0};
        helper(root, start);

        vector<vector<int>> res;
        for(auto col : cols){
            sort(col.second.begin(), col.second.end(), comp);
            vector<int> colRes;
            for(auto p: col.second){
                colRes.push_back(p.second);
            }

            res.push_back(colRes);
        }
        return res;
    }

    void helper(TreeNode* curr, pair<int,int> pos){
        if(curr == nullptr) return;

        int row = pos.first;
        int col = pos.second;

        cols[col].push_back({row, curr->val});

        helper(curr->left, {row+1, col-1});
        helper(curr->right, {row+1, col+1});
    }
};
```