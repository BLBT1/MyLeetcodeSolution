class Solution {
public:
    int palindromePartition(string s, int K) 
    {    
        int n = s.size();
        s = "#"+s;
        vector<vector<int>> dp1(n+1, vector<int>(n+1, 0));
        for(int i = 0; i <= n; ++i)
            dp1[i][i] = 0;

        for(int i = 1; i <= n; ++i)
            if(s[i] == s[i-1])
                dp1[i-1][i] = 0;
            else
                dp1[i-1][i] = 1;

        for(int len = 3; len <= n; ++len)
        {
            for(int i = 1; i+len-1 <= n; ++i)
            {
                int j = i+len-1;
                if(s[i] == s[j])
                    dp1[i][j] = dp1[i+1][j-1];
                else
                    dp1[i][j] = dp1[i+1][j-1]+1;
            }
        }
        
        vector<vector<int>> dp(n+1, vector<int>(K+1, INT_MAX/2));
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int k = 1; k <= min(i, K); ++k)
            {
                for(int j = k; j <= i; ++j)
                {
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1] + dp1[j][i]);
                }
            }
        }

        return dp[n][K];
    }
};


// {XXXXXXXXXXX} [jXXXXi]
//  1~k-1 的区间  kth区间

// dp[i][k] => the minimal number of characters that you need to change to divide the string
//             for dividing s[1:i] into k substrings

// dp[i][k] = min(dp[j-1][k-1] + helper(s[j:i])) for j = k ... i

// for(int i = 1; i <= n; ++i)
// {
//     for(int k = 1; k <= min(i, K); ++k)
//     {
//         for(int j = k; j <= i; ++j)
//         {
//             dp[i][k] = min(dp[i][k], dp[j-1][k-1] + helper(s[j:i]));
//         }
//     }
// }

// return dp[n][k];


// this helper(s[i:i]) can be solved use type2 区间问题
// X XXX YYYY XXX
// 0   5
// dp1[i][j] => min number of chars to change to make s[i:j] palindrome

// for(int i = 0; i <= n; ++i)
//     dp1[i][i] = 0;

// for(int i = 2; i <= n; ++i)
//     if(s[i] == s[i-1])
//         dp1[i-1][i] = 0;
//     else
//         dp1[i-1][i] = 1;

// for(int len = 3; len <= n; ++len)
// {
//     for(int i = 1; i+len <= n; ++i)
//     {
//         int j = i+len;
//         if(s[i] == s[j])
//             dp1[i][j] = dp1[i+1][j-1];
//         else
//             dp1[i][j] = dp1[i+1][j-1]+1;
//     }
// }


