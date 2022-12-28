class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        if (nums[0] == 1)
        {
            dp[0][0] = 1;
        }
        else
        {
            dp[0][1] = 1;
        }
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == 0)
            {
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = 0;
            }
            else
            {
                dp[i][1] = dp[i - 1][1] + 1;
                dp[i][0] = dp[i - 1][0] + 1;
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res = max(res, max(dp[i][0], dp[i][1]));
        }
        return res;
    }
};

// def dp[i][j] as at i in nums, the longest consecutive one if at j state

// states:
//     0 -> has not fliped 1
//     1 -> has fliped one