class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for(int len = 1; len <= n; ++len)
        {
            for(int i = 1; i+len-1 <= n; ++i)
            {
                int j = i+len-1;
                for(int k = i; k <= j; ++k )
                {
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
};

// int k to find the ballon that burst the last
// 假设最后一个炸的是i
// [XXX i XXX]
// dp[i][i] = nums[i]

// dp[i][j] = 
    

// 因为我们首先找到了小区间的最大值，所以 dp[i][k-1] and dp[k+1][j] has been already finalized
// i XXXX k XXXXX j

// dp[i][j] = max(dp[i][k-1] + nums[i-1]*nums[k]*nums[j+1] + dp[k+1][j]); for k = i...j 