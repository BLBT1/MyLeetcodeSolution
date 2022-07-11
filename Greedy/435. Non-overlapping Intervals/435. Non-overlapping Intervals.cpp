class Solution
{
    struct comp
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[1] < b[1];
        }
    };

public:
    int eraseOverlapIntervals(vector<vector<int>> &itv)
    {
        // greedy
        // we want to save more room for the later intervals => sort by the end time
        sort(itv.begin(), itv.end(), comp());
        int cnt = 0; // max number of intervals to remain
        int i = 0;
        while (i < itv.size())
        {
            cnt++;
            // find all the conflict
            int j = i + 1;
            while (j < itv.size() && itv[j][0] < itv[i][1])
                ++j;
            i = j;
        }
        return itv.size() - cnt;
    }
};

// [[1,2],[2,3],[1,3],[3,4]]