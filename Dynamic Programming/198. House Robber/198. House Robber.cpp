class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int const n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(2, 0));
        int take = nums[0];
        int not_take = 0;
        for(int i = 1; i < n; ++i)
        {
            int prev_take = take;
            int prev_not_take = not_take;
            take = prev_not_take + nums[i];
            not_take = max(prev_take, prev_not_take);
        }
        
        return max(take, not_take);
    }
};

// O(N) time + O(1) space

// [1, 2, 3, 1]

// dp[i][j] => 
//     dp[i][0] => the max we can get if we rob house i
//     dp[i][1] => the max we can get if we do not rob house i


// dp[i][1] = dp[i][0]+nums[i]
// dp[i][0] = max(dp[i][1], dp[i][0])