class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int K) 
    {    
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
        dp[0][0] = 0;
        
        // i 个数字分成0组的定义是非法的，设为INT_MIN/2, 这样就用不到他们了
        for (int i=1; i<=n; i++)
            dp[i][0] = INT_MIN/2; 
        
        vector<double> presum(n+1);
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
                    dp[i][k] = max(dp[i][k], dp[j-1][k-1]+(presum[i]-presum[j-1])*1.0/(i-j+1)*1.0);
                }
            }
        }
        
        return *max_element(dp[n].begin(), dp[n].end());
    }
};


// XXXXXXX jXXXi

// dp[i][k] => max(dp[j-1][k-1]  + avg(nums[j:i]), dp[i][j]);
// [0, 9, 1, 2, 3, 9]
// [0, 9, 10, 12, 15, 24]
//  0      2       
 