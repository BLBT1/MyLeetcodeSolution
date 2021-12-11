/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution
{
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1]; // want to be longest first, so we can cover the following
    }

public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        // sort + pq
        // 按首端点排序
        // ##----
        //   ----
        // than the beginning of the first interval is unique and cannot be covered
        sort(intervals.begin(), intervals.end(), comp);
        const int n = intervals.size();
        int i = 0;
        int cnt = 0;
        while (i < n)
        {
            int j = i + 1;
            cnt++;
            while (j < n && intervals[i][1] >= intervals[j][1])
            {
                // interval[j] is covered by interval[i]
                ++j;
            }
            i = j;
        }
        return cnt;
    }
};
// @lc code=end

// sorted by thae starting point
// => min num of intervals to cover the whole range

// [1,4], [1,2], [3,4]
//  i
//                      j
