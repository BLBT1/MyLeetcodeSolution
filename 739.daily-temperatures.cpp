/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        const int n = temperatures.size();

        stack<int> Stack; // mono stack de.
        vector<int> res(n, 0);

        for (int i = 0; i < n; ++i)
        {
            while (!Stack.empty() &&
                   temperatures[Stack.top()] < temperatures[i])
            {
                res[Stack.top()] = i - Stack.top();
                Stack.pop();
            } // while

            Stack.push(i);
        } //for

        while (!Stack.empty())
        {
            res[Stack.top()] = 0;
            Stack.pop();
        } // while

        return res;
    }
};
// @lc code=end
