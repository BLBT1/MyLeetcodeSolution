/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        stack<int> Stack; // mono de.
        int res = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (Stack.empty() || nums[Stack.top()] > nums[i])
            {
                Stack.push(i);
            }
        } // for

        for (int j = nums.size() - 1; j >= 0; --j)
        {
            while (!Stack.empty() && nums[Stack.top()] <= nums[j])
            {
                res = max(res, j - Stack.top());
                Stack.pop();
            } //while
        }     //for

        return res;
    }
};
// @lc code=end
