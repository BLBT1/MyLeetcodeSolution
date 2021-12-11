/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution
{
    bool dp[16][16];
    vector<vector<string>> res;

public:
    vector<vector<string>> partition(string s)
    {
        // this problem has two parts:
        // 1. use dp to record if [i:j] is palindrome (O(n^2))
        // 2. dfs(2^n)

        const int n = s.size();
        // do the dp
        // rescursive relation:
        // dp[i][j] = s[i] == (s[j] && dp[i+1][j-1] == true)
        // do for the range len == 1
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = 0; i + 1 < n; i++)
            dp[i][i + 1] = s[i] == s[i + 1];
        for (int len = 3; len <= n; len++)
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1];
                else
                    dp[i][j] = false;
            }

        // do dfs
        vector<string> ans; // curr paritioning
        int curr = 0;
        dfs(s, curr, ans);
        return res;
    }

    void dfs(string &s, int curr, vector<string> &ans)
    {
        const int n = s.size();
        if (curr == n)
        {
            res.push_back(ans);
            return;
        }

        for (int j = curr; j < n; ++j)
        {
            if (dp[curr][j])
            {
                ans.push_back(s.substr(curr, j - curr + 1));
                dfs(s, j + 1, ans);
                ans.pop_back();
            }
        } //for
    }
};
// @lc code=end
