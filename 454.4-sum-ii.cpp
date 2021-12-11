/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2,
                     vector<int> &nums3, vector<int> &nums4)
    {
        int res = 0;
        unordered_map<int, int> map; //{a+b, frq}
        for (auto a : nums1)
            for (auto b : nums2)
                map[a + b]++;

        for (auto c : nums3)
            for (auto d : nums4)
            {
                if (map.find(-(c + d)) != map.end())
                    res += map[-c - d];
            }

        return res;
    }
};
// @lc code=end
