class Solution
{
public:
    int minCost(vector<vector<int>> &nums)
    {
        const int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        dp[0][0] = nums[0][0];
        dp[0][1] = nums[0][1];
        dp[0][2] = nums[0][2];
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + nums[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + nums[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + nums[i][2];
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// dp[i][j] min cost of paint the i the house with the color j
