class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        // first num is not picked
        vector<vector<int>> dp1(n - 1, vector<int>(2, 0));
        dp1[0][1] = nums[1];
        for (int i = 1; i < n - 1; ++i)
        {
            dp1[i][1] = dp1[i - 1][0] + nums[i + 1];
            dp1[i][0] = max(dp1[i - 1][0], dp1[i - 1][1]);
        }

        // the last num is not picked
        vector<vector<int>> dp2(n - 1, vector<int>(2, 0));
        dp2[0][1] = nums[0];
        for (int i = 1; i < n - 1; ++i)
        {
            dp2[i][1] = dp2[i - 1][0] + nums[i];
            dp2[i][0] = max(dp2[i - 1][0], dp2[i - 1][1]);
        }

        return max(max(dp1[n - 2][0], dp1[n - 2][1]),
                   max(dp2[n - 2][0], dp2[n - 2][1]));
    }
};
// [2,[3,2,1]
//  0  1 2 3
