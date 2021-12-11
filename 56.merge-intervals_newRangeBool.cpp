/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), comp);

        bool newRange = true; // if we need a new range
        vector<int> range = intervals[0];
        for (int i = 0; i < intervals.size(); ++i)
        {
            int begin = intervals[i][0];
            int end = intervals[i][1];
            if (begin <= range[1])
            {
                range[1] = max(range[1], end);
            }
            else
            {
                newRange = true;
                res.push_back(range);
            }
            if (newRange)
            {
                range[0] = begin;
                range[1] = end;
                newRange = false;
            }
        } //for
        res.push_back(range);
        return res;
    }
};
// @lc code=end

// internval[i] = [starti, endi]
//intervals = [[1,3],[2,6],[8,10],[15,18]]
//              i
// [8,10]
// currEnd
// currBegin
// merge overlapping intervals
// newRange (bool)