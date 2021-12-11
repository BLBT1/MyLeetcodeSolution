/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        if (heights.size() == 0)
            return 0;
        if (heights.size() == 1)
            return heights[0];

        heights.push_back(0);
        heights.insert(heights.begin(), 0);
        const int n = heights.size();
        stack<int> Stack;

        Stack.push(0);

        int res = 0;

        for (int i = 0; i < n; i++)
        {
            while (heights[Stack.top()] > heights[i])
            {

                int h = heights[Stack.top()];
                Stack.pop();
                int w = i - Stack.top() - 1;
                res = max(res, h * w);
            } //while
            Stack.push(i);
        }

        return res;
    }
};
// @lc code=end
