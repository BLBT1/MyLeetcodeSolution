class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MAX / 2));
        if (s[0] == '0')
        {
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        else
        {
            dp[0][1] = 0;
            dp[0][0] = 1;
        }

        for (int i = 1; i < n; ++i)
        {
            if (s[i] == '1')
            {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][0] = dp[i - 1][0] + 1;
            }
            else
            {
                dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][0] + 1);
                dp[i][0] = dp[i - 1][0];
            }
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

// "00 11 0"
// // dp[i] => min flips to make s[0:i] increasing
//     dp[i][0] => end with 0
//     dp[i][1] => end with 1

//  if(s[i] == 1)
//      dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
//      dp[i][0] = dp[i-1][0]+1;
// else
//     dp[i][1] = min(dp[i-1][1]+1, dp[i-1][0]+1);
//     dp[i][0] = dp[i-1][0];