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
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(res - target) > abs(sum - target))
                {
                    res = sum;
                }
                if (sum > target)
                {
                    --r;
                }
                else if (sum < target)
                {
                    ++l;
                }
                else
                {
                    return target;
                }
            }
        }
        return res;
    }
};
// @lc code=end
