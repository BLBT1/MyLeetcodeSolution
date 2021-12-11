/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        //* my thought: for each i,
        //* use two ptrs to find the a pair clost to the target
        const int n = nums.size();
        int res = nums[0] + nums[1] + nums[2];

        if (n == 3)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i)
        {
            //def 2 ptrs
            int j = i + 1;
            int k = n - 1;
            int sum;
            while (j < k)
            {
                sum = nums[i] + nums[j] + nums[k];

                int diff = abs(target - sum);
                int curr_diff = abs(target - res);
                if (diff < curr_diff)
                {
                    res = sum;
                }

                if (sum < target)
                {
                    ++j;
                }
                else if (sum > target)
                {
                    --k;
                }
                else
                {
                    return sum;
                }
            } // while

        } // for
        return res;
    }
};
// @lc code=end
