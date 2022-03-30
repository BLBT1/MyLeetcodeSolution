/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int res = 0;
        int cnt = 0;
        for (; r < nums.size(); ++r)
        {
            if (nums[r] % 2 == 1)
            {
                cnt++;
            }
            while (cnt > k)
            {
                if (nums[l] % 2 == 1)
                {
                    cnt--;
                }
                l++;
            }
            res += r - l + 1;
        }
        return res;
    }
};
// @lc code=end
