class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) 
    {    
        const int m = s1.size();
        const int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

// O(NM) time + O(NM) space
// dp[i][j] => longest common subsequence for [0:i] in s1 and [0:j] in s2;
