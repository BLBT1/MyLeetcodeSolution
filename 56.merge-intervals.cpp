/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution
{
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first != b.first)
            return a.first < b.first;
        // --------
        // ----
        // --
        // this is ok, as cnt never turn to be 0 in the middle
        return a.second > b.second;
    }

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 扫描线思维
        // 1 {start，1}， {end，-1}
        // 2 sort
        // 3 use cnt to record # of curr overlapping
        // 4 a interval merged interval lifetime:
        // cnt = 0 -> cnt = 1 -> cnt = 2 ... -> cnt = 1 -> cnt = 0
        // thus, when cnt = 1, new interval begin
        // when when cnt back to 0, this interval end + push into res
        vector<vector<int>> res;
        vector<pair<int, int>> times;
        for (int i = 0; i < intervals.size(); ++i)
        {
            times.push_back({intervals[i][0], 1});
            times.push_back({intervals[i][1], -1});
        } //for

        sort(times.begin(), times.end(), comp);

        int cnt = 0; // # of overlapping intervals
        vector<int> currInterval(2, 0);
        for (auto &p : times)
        {
            if (p.second == 1)
            {
                cnt++;
                if (cnt == 1)
                    currInterval[0] = p.first;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    currInterval[1] = p.first;
                    res.push_back(currInterval);
                }
            }
        } //for
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