class Solution
{
public:
    int splitArray(vector<int> &nums, int K)
    {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        vector<int> presum(n + 1);
        int sum = 0;
        for (int i = 0; i <= n; ++i)
        {
            sum += nums[i];
            presum[i] = sum;
        }
        vector<vector<int>> dp(n + 1, vector<int>(K + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int k = 1; k <= min(K, i); ++k)
            {
                for (int j = k; j <= i; ++j)
                {
                    dp[i][k] = min(max(dp[j - 1][k - 1], presum[i] - presum[j - 1]), dp[i][k]);
                }
            }
        }
        return dp[n][K];
    }
};

//  0  1  3  6  10 15
// [1, 2, 3, 4, 5]
//        j        i

// dp[i][K] => split first i element into k parts
// dp[i][k] = min(max(dp[j-1][k-1],sum[i:j]),dp[i][j]) for j = k-1 ... i

// for i = 0 ...  k
//     for k = 1 ... K
//       for j = k-1 ... i