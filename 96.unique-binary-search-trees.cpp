/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        // [0 : n]
        // dp[i] <- num of bst for i nodes
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            //j the number of nodes for the left subtree
            for (int j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end
