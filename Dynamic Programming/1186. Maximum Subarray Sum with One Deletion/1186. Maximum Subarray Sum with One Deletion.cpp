class Solution
{
public:
    int maximumSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        dp[0][0] = arr[0];
        dp[0][1] = arr[0]; // 删完后至少需要还有一个element
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(arr[i], dp[i - 1][0] + arr[i]);
            dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i - 1][0]);
        }

        int res = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};

// def dp[i][j] max subarray sum for s[0: i] at j state
// states:
//     0 -> del not used the max subarray
//     1 -> used del max subarray
