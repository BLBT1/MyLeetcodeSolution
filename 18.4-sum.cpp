/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        //* my thought:
        //* two ptrs with 2 ptrs inner
        const int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int a = 0;
        for (; a < n - 3; ++a)
        {
            //* remove duplicate
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            int b = a + 1;
            for (; b < n - 2; ++b)
            {
                //* remove duplicate
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                int left = b + 1;
                int right = n - 1;
                while (left < right)
                {
                    if (nums[a] + nums[b] + nums[left] + nums[right] > target)
                        --right;
                    else if (nums[a] + nums[b] + nums[left] + nums[right] < target)
                        ++left;
                    else
                    {
                        res.push_back({nums[a], nums[b], nums[left++], nums[right--]});
                        //* remove duplicate
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            } //for b
        }     //for a
        return res;
    }
};
// @lc code=end
