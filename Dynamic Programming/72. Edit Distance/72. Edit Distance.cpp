class Solution {
public:
    int minDistance(string w1, string w2) 
    {
        int m = w1.size();
        int n = w2.size();
        w1 = "#" + w1;
        w2 = "#" + w2;
        auto dp = vector<vector<int>>(m+1, vector<int>(n+1));
        for(int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for(int j = 0; j <= n; ++j)
            dp[0][j] = j;
        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(w1[i] == w2[j])
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    //               delete i       delete j     replace i to j     
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        
        return dp[m][n];
    }
};

// dp[i][j] => edit distance to convert w1[1:i] to w2[1:j]

// XXXXXX i XXXXX
// YYYYYY j YYYYYYY