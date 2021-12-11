/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
using PII = pair<int, int>;
class Solution
{

    struct comp
    {
        bool operator()(PII &a, PII &b)
        {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
    };

public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule)
    {
        priority_queue<PII, vector<PII>, comp> pq;
        for (int i = 0; i < schedule.size(); ++i)
        {
            for (int j = 0; j < schedule[i].size(); ++j)
            {
                pq.push({schedule[i][j].start, 1});
                pq.push({schedule[i][j].end, -1});
            }
        }

        int overlap = 0;
        vector<Interval> res;
        Interval curr(-1, -1);
        while (!pq.empty())
        {
            auto [time, num] = pq.top();
            pq.pop();
            overlap += num;
            if (overlap == 0 && num == -1)
            {
                curr.start = time;
            }
            else if (overlap == 1 && num == 1 && curr.start != -1)
            {
                curr.end = time;
                res.push_back(curr);
            }
        }

        return res;
    }
};

//  ----|   |
//      |   |----
//  ----|   |
//              ----

// overlap 1->0 is the begin
// overlap 0->1 is the end