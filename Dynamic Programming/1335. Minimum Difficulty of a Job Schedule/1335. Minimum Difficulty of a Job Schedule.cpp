class Solution {
public:
    int minDifficulty(vector<int>& nums, int K)
    {
        // 410
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp(n+1, vector<int>(K+1, INT_MAX/2));
        dp[0][0] = 0;
        
        for (int i=1; i<=n; i++)
            dp[i][0] = INT_MAX/2; 
        
        for(int i = 1; i <= n; ++i)
        {
            for(int k = 1; k <= min(K, i); ++k)
            {
                 int mx = nums[i];
                for (int j=i; j>=k; j--)
                {
                    mx = max(mx, nums[j]);
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1]+mx);
                }
            }
        }
        if (dp[n][K] >= INT_MAX/2) 
            return -1;
        else 
            return dp[n][K]; 
    }
};