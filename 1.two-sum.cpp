/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution
{

public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //* <diff, val>
        unordered_map<int, int> diff_map;
        vector<int> res; // record the index
        res.resize(2);
        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = diff_map.find(nums[i]);
            if (it == diff_map.end()) // if we don't find it
            {
                diff_map[target - nums[i]] = i;
            }
            else
            {
                res[0] = it->second;
                res[1] = i;
            }
        } //for
        return res;
    } //twoSum()
};
// @lc code=end
