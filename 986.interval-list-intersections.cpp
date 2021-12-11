/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
using PII = pair<int, int>;

class Solution
{
    static bool comp(PII &a, PII &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    }

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<PII> time;
        for (auto &s : firstList)
        {
            time.push_back({s[0], 1});
            time.push_back({s[1], -1});
        }
        for (auto &s : secondList)
        {
            time.push_back({s[0], 1});
            time.push_back({s[1], -1});
        }

        sort(time.begin(), time.end(), comp);

        int overlap = 0;
        PII range;
        vector<vector<int>> res;
        for (auto &t : time)
        {
            int x = t.second;
            overlap += x;
            if (x == 1 && overlap == 2)
            {
                range.first = t.first;
            }
            else if (x == -1 && overlap == 1)
            {
                range.second = t.first;
                res.push_back({range.first, range.second});
            }
        }
        return res;
    }
};
// @lc code=end
