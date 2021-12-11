class Solution
{
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }

public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        vector<vector<int>> times; //{begin/end, 1/ -1}
        // 扫描线
        for (auto &interval : intervals)
        {
            times.push_back({interval[0], 1});
            times.push_back({interval[1], -1});
        }

        sort(times.begin(), times.end(), comp);

        int count = 0;
        int res = 0;
        for (auto &t : times)
        {
            count += t[1];
            res = max(res, count);
        }

        return res;
    }
};