class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 运用的是01 背包的思想，对于一个sum s 而言
        // 想知道 sum[20], 我们要遍历所有的 sum[20-x], 看是不是可以
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
            return false;
        int n = nums.size();
        // dp[i][sum] => if use the first i item can get sum
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
        for (int i = 0; i < n; ++i)
            dp[i][0] = true;
        for (int i = 1; i < n; ++i)
        {
            for (int s = 1; s <= sum / 2; ++s)
            {
                if (s >= nums[i] && dp[i - 1][s - nums[i]] == true)
                    dp[i][s] = true;
                if (dp[i - 1][s] == true)
                    dp[i][s] = true;
            }
        }

        return dp[n - 1][sum / 2];
    }
};