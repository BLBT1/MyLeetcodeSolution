/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        const int n = text1.size();
        const int m = text2.size();
        text1 = '#' + text1;
        text2 = '#' + text2;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};

// abcde
// ace
// LCS: ace = 3

// #abc
// #abc
//
// 0 1 1 1
// 0 1 2 2
// 0 1 2 3
// 0 1 2 3

// define
// dp[i][j] -> the LCS for [0:i] & [0:j] of two given string

// @lc code=end
