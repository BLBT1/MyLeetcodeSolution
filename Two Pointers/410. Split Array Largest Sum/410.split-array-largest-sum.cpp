/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        // binary search by value
        // min: max element in the nums
        // max: sum of all element
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (check(nums, m, mid))
            {
                r = mid; // mid is a possible res
            }
            else
            {
                l = mid + 1; // mid is not possible
            }
        }
        return l;
    }

    bool check(vector<int> &nums, int m, int val)
    {
        // greedy
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = i;
            int sum = 0;
            while (j < nums.size() && sum + nums[j] <= val)
            {
                sum += nums[j];
                j++;
            }
            cnt++;
            i = j - 1;
        }
        return cnt <= m;
    }
};
// @lc code=end
