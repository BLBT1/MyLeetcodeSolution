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
    unordered_map<int, int> cnts;
    int maxCnt;

public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        maxCnt = 1;
        vector<int> res;
        postorder(root);
        for (auto &p : cnts)
        {
            if (p.second == maxCnt)
                res.push_back(p.first);
        }
        return res;
    }

    int postorder(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int leftSum = postorder(root->left);
        int rightSum = postorder(root->right);
        int sum = root->val + leftSum + rightSum;
        cnts[sum]++;
        maxCnt = max(maxCnt, cnts[sum]);
        return sum;
    }
};