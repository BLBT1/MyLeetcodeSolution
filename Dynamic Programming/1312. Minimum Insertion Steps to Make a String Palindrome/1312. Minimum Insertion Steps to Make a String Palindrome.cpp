class Solution {
public:
    int minInsertions(string s) 
    {
        // reverse s，then find scs
        string rs = s;
        reverse(rs.begin(), rs.end());
        int m = s.size();
        int n = rs.size();
        s = "#"+s;
        rs = "#"+rs;
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX/2));
        dp[0][0] = 0;
        for(int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for(int j = 1; j <= n; ++j)
            dp[0][j] = j;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(s[i] == rs[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
            }
        }
        
        return dp[m][n] - s.size() + 1; // +1 for #
    }
};

// XXXXX i
// YYYYYY j