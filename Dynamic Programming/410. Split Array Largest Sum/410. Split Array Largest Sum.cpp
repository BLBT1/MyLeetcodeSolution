class Solution {
public:
    int splitArray(vector<int>& nums, int K) 
    {    
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX/2));
        dp[0][0] = 0;
        
        for (int i=1; i<=n; i++)
            dp[i][0] = INT_MAX/2; 
        
        vector<int> presum(n+1);
        int sum = 0;
        for(int i = 0; i <= n; ++i)
        {
            sum += nums[i];
            presum[i] = sum;
        }
        
        for(int i = 1; i <= n; ++i)
        {
            for(int k = 1; k <= min(K, i); ++k)
            {
                for(int j = k; j <= i; ++j)
                {
                    dp[i][k] = min(dp[i][k], max(dp[j-1][k-1],presum[i]-presum[j-1]));
                }
            }
        }
        
        return dp[n][K]; 
    }
};
