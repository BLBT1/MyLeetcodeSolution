/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        const int n = height.size();

        if (n < 3)
            return 0;

        //* my thought:
        //* use mono stack to use O(n) to find the pos of
        //* next greater or eq element pos
        stack<int> Stack; // monotonic stack de.
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            while (!Stack.empty() && height[Stack.top()] <= height[i])
            {
                int base = height[Stack.top()];
                Stack.pop();
                if (!Stack.empty())
                {
                    int h = min(height[i], height[Stack.top()]) - base;
                    int w = i - Stack.top() - 1;
                    res += h * w;
                }
            } //while
            Stack.push(i);
        } // for

        return res;
    }
};
// @lc code=end
