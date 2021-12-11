/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nums;

        if (nums.size() == 1)
            return vector(1, -1);

        vector<int> res(nums.size(), -1);
        stack<int> Stack; // mono de.

        for (int i = 0; i < 2 * nums.size(); ++i)
        {
            int idx = i >= nums.size() ? i - nums.size() : i;
            while (!Stack.empty() && nums[Stack.top()] < nums[idx])
            {
                int nge = Stack.top();
                res[nge] = nums[idx];
                Stack.pop();
            } //while

            Stack.push(idx);
        } //for

        return res;
    }
};
// @lc code=end
