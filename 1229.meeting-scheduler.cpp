using PII = pair<int, int>;
class Solution
{
    static bool comp(PII &a, PII &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }

public:
    vector<int> minAvailableDuration(vector<vector<int>> &slots1,
                                     vector<vector<int>> &slots2,
                                     int duration)
    {
        // sweeping line method
        // overlap: 1->2 begin time
        // overlap: 2->1 end time
        // if end - begin >= duration
        // return {begin,end}
        vector<PII> time;
        for (auto &s : slots1)
        {
            time.push_back({s[0], 1});
            time.push_back({s[1], -1});
        }
        for (auto &s : slots2)
        {
            time.push_back({s[0], 1});
            time.push_back({s[1], -1});
        }

        sort(time.begin(), time.end(), comp);

        int overlap = 0;
        PII range;
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
                if (range.second - range.first >= duration)
                {
                    return {range.first, range.first + duration};
                }
            }
        }
        return {};
    }
};