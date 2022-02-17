/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        const int n = s.size();
        int res = 1;
        vector<vector<int>> dp(n, vector<int>(n, 1));

        for (int i = 0; i + 1 < n; ++i)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 2;
            }
        }

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    // missed this
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        } //for

        return dp[0][n - 1];
    }
};

// // find the longest palindromic subseq
// dp[i][j] <= longest palindromic subseq in s[i:j]
// if s[i] == s[j]
//     dp[i][j] = dp[i+1][j-1]+2
// else
//     dp[i][j] = dp[i+1][j-1]

// bbbab
//
// @lc code=end
