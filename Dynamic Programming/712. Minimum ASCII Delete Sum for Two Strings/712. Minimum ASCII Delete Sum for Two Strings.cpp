class Solution {
public:
    int minimumDeleteSum(string w1, string w2) 
    {
        int m = w1.size();
        int n = w2.size();
        w1 = "#"+w1;
        w2 = "#"+w2;
        auto dp = vector<vector<int>>(m+1, vector<int>(n+1));
        dp[0][0] = 0;
        int sum = 0;
        for(int i = 1; i <= m; ++i)
        {   
            sum += w1[i];
            dp[i][0] = sum;
        }
        sum = 0;
        for(int j = 1; j <= n; ++j)
        {
            sum += w2[j];
            dp[0][j] = sum;
        };
        
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(w1[i] == w2[j])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j] + w1[i], dp[i][j-1] + w2[j]);
                }
            }
        }            
        return dp[m][n];
    }
};