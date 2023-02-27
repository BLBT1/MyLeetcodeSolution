class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        word1.insert(word1.begin(), '#');
        word2.insert(word2.begin(), '#');

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for (int j = 1; j <= n; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }
        return dp[m][n];
    }
};

// dp[i][j] = min operation to convert word1[:i] to word2[:j]
// XXXXhorse
//     i
// XXXXos
//    j

// if(word1[i] == word2[j])
//     dp[i][j] = dp[i-1][j-1];
// else
//                    replace i to j     insert word2[j]  delete word1[i]
//     dp[i][j] = min{dp[i-1][j-1]+1,    dp[i][j-1]+1,   dp[i-1][j]+1};