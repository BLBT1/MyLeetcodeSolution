/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // use the algo in eecs477 lec14
        // O(n) time
        // O(1) space
        int c1 = 0, c2 = 0;
        int elt1, elt2;
        for (auto &i : nums)
        {
            if (c1 == 0 && elt2 != i)
                elt1 = i;
            else if (c2 == 0 && elt1 != i)
                elt2 = i;

            if (i == elt1)
                ++c1;
            else if (i == elt2)
                ++c2;
            else
            {
                --c1;
                --c2;
            }
        }
        // check promise
        vector<int> res;
        c1 = 0;
        c2 = 0;
        for (auto &i : nums)
        {
            if (i == elt1)
                ++c1;
            if (i == elt2)
                ++c2;
        }
        if (c1 > nums.size() / 3)
            res.push_back(elt1);
        if (c2 > nums.size() / 3)
            res.push_back(elt2);

        return res;
    }
};
// @lc code=end
