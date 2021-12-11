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
        /*
        * idea: the result is in the interval: [max(nums), sum(nums)+1)
        * Guess a candidite C, compute the # of groups k needed to partition
        * s.t. for all group i, sum(group i) <= C.
        * we say C is valid if k is m
        * We do check the partition by greedy parition
        * Note:(1) dp can also used to solve this program
        * (2) binary search only work when all elements in array is non-negative
        */
        int l = *std::max_element(nums.begin(), nums.end());
        int r = std::accumulate(nums.begin(), nums.end(), 0);
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (!isValidCan(nums, m, mid))
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }

    //* this is helper fxn to check if the given candid is valid
    //* greedy partition
    bool isValidCan(const vector<int> &nums, size_t k, size_t C)
    {
        size_t num_group = 1;
        size_t temp_sum = 0;
        for (const auto &num : nums)
        {
            if ((temp_sum + num) > C)
            {
                ++num_group;
                temp_sum = num;
            }
            else
            {
                temp_sum += num;
            }
        }
        return num_group <= k;
    }
};
// @lc code=end
