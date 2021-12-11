/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        const int n = nums.size();
        vector<vector<int>> res;

        //*sort nums for 2 ptr
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i)
        {
            //* remove duplicate
            if (i && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = n - 1;
            int t = -nums[i];
            while (j < k)
            {
                int sum = nums[j] + nums[k];
                if (sum > t)
                    --k;
                else if (sum < t)
                    ++j;
                else
                {
                    //* we find a ans + remove duplicate
                    res.push_back({nums[i], nums[j], nums[k]});

                    while (j < k && nums[j] == nums[j + 1])
                        ++j;
                    while (j < k && nums[k] == nums[k - 1])
                        --k;

                    ++j;
                    --k;
                }
            } // while
        }     //for
        return res;
    } //3sum()
};
// @lc code=end
