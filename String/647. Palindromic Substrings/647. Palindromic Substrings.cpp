class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[i][j] => s[i:j]
        for (int i = 0; i < n; ++i)
        {
            dp[i][i] = true;
            res++;
        }
        for (int i = 1; i < n; ++i)
        {
            dp[i - 1][i] = (s[i - 1] == s[i]);
            if (dp[i - 1][i])
                res++;
        }

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                if (dp[i][j])
                    res++;
            }
        }

        return res;
    }
};