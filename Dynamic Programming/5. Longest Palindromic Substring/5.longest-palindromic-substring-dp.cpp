/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int res = 1;
        pair<int, int> ans = {0, 0};
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // if len = 1
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
        }

        // if len = 2
        for (int i = 0; i + 1 < n; ++i)
        {
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (res == 1 && dp[i][i + 1] == true)
            {
                res = 2;
                ans = {i, i + 1};
            }
        }

        // over all length
        for (int len = 3; len <= n; ++len)
        {
            // over all start
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                if (dp[i + 1][j - 1] == true)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                if (dp[i][j] == true && j - i + 1 > res)
                {
                    res = j - i + 1;
                    ans = {i, j};
                }
            }
        } // for
        return s.substr(ans.first, ans.second - ans.first + 1);
    }
};

// s = "babad"
// "bab"

// dp[i][j] <- define s[i:j] is a palindrome

// dp[i][j] = dp[i+1][j-1] && s[i] == s[j]
// 区间型dp
// @lc code=end
