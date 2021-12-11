/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        //O(n) + O(n)
        //* greedy
        //* assume each num in nums to be the middle
        //* find all the min num from its left
        const int n = nums.size();
        if (n < 3)
            return false;

        vector<int> leftMin;
        leftMin.reserve(n);

        leftMin.push_back(INT_MAX);

        for (int i = 1; i < n; ++i)
            leftMin[i] = min(leftMin[i - 1], nums[i - 1]);

        //* monotonic stack
        //* assume each num in nums to be the middle
        //* find the greatest element that is less than it
        stack<int> dS;
        int second = INT_MIN;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!dS.empty() && dS.top() < nums[i])
            {
                second = dS.top();
                dS.pop();
            }

            if (second > leftMin[i])
                return true;
            dS.push(nums[i]);
        }
        return false;
    }
};
// @lc code=end
