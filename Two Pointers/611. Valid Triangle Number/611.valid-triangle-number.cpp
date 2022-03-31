/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int k = 2; k < nums.size(); k++)
        {
            int l = 0, r = k - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] > nums[k])
                {
                    res += r - l;
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

// [2,2,3,4]
//