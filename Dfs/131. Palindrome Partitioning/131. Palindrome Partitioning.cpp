class Solution
{
    vector<vector<string>> res;
    vector<string> list;
    int n;
    string s;

public:
    vector<vector<string>> partition(string s)
    {
        // dp[i][j] => s[i:j] is palindrome
        n = s.size();
        this->s = s;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for (int i = 1; i < n; ++i)
            dp[i - 1][i] = (s[i - 1] == s[i]);

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }

        dfs(dp, 0);

        return res;
    }

    void dfs(vector<vector<bool>> &dp, int curr)
    {
        if (curr == n)
        {
            res.push_back(list);
            return;
        }
        for (int i = curr; i < n; ++i)
        {
            if (dp[curr][i])
            {
                list.push_back(s.substr(curr, i - curr + 1));
                dfs(dp, i + 1);
                list.pop_back();
            }
        }
    }
};