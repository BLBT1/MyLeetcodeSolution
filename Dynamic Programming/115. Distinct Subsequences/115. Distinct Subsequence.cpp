class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        s = "#" + s;
        t = "#" + t;
        auto dp = vector<vector<unsigned long long>>(m + 1, vector<unsigned long long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = 1;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = 0;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i] == t[j])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[m][n];
    }
};

// dp[i][j] => num of dist subseq of s[1:i] == t[1:j]
// XXXXXXXX i

// YYYYYY j

// if(s1[i] == s2[j])
//     dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
// else
//     dp[i][j] = dp[i-1][j-1]
