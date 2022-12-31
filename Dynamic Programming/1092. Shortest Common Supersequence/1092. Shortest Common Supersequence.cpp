class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; ++i)
            dp[i][0] = i;
        for(int j = 1; j <= n; ++j)
            dp[0][j] = j;
    
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
                    dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1);
                }
            }
        }     
        int i = m;
        int j = n;
        string res = "";
        while(i-1 >= 0 && j-1 >= 0)
        {
            if(s1[i-1] == s2[j-1])
            {
                res.push_back(s1[i-1]);
                i--; j--;
            }
            else
            {
                if(dp[i][j] == dp[i-1][j]+1)
                {
                    res.push_back(s1[i-1]);
                    --i;
                }
                else if(dp[i][j] == dp[i][j-1]+1)
                {
                    res.push_back(s2[j-1]);
                    --j;
                }
            }
        }

        while(i-1 >= 0)
        {
            res.push_back(s1[i-1]);
            --i;
        }

        while(j-1 >= 0)
        {
            res.push_back(s2[j-1]);
            --j;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// XXXXX i
// YYYYYYY j