/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> maxP(n);
        vector<int> minP(n);
        maxP[0] = nums[0];
        minP[0] = nums[0];
        int res = maxP[0];

        for (int i = 1; i < n; ++i)
        {
            maxP[i] = max(max(maxP[i - 1] * nums[i], minP[i - 1] * nums[i]), nums[i]);
            minP[i] = min(min(maxP[i - 1] * nums[i], minP[i - 1] * nums[i]), nums[i]);
            res = max(res, maxP[i]);
        }
        return res;
    }
};
// @lc code=end
