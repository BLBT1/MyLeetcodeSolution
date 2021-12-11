/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution
{
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // 这个题是区间型贪心法的模板题
        // max num of interval that non-overlapping -> sorted by end point
        sort(intervals.begin(), intervals.end(), comp);
        const int n = intervals.size();
        int i = 0;
        int cnt = 0;
        while (i < n)
        {
            cnt++;
            int j = i + 1;
            while (j < n && intervals[j][0] < intervals[i][1])
                ++j;
            i = j;
        }

        return n - cnt;
    }
};
// @lc code=end
