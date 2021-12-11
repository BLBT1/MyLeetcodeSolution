/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
class Solution
{
    // sort array by the begin day
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] < b[1];
    }

    struct myComp
    {
        bool operator()(vector<int> &a, vector<int> &b)
        {
            return a[1] > b[1];
        }
    };

public:
    // sort + pq + greedy
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), comp);
        priority_queue<vector<int>, vector<vector<int>>, myComp> pq;
        const int endDay = 100000;
        int currEvent = 0;
        int res = 0;
        // starting from day
        for (int day = 1; day <= endDay && (currEvent != events.size() || !pq.empty()); ++day)
        {
            while (currEvent < events.size() && events[currEvent][0] == day)
            {
                pq.push(events[currEvent]);
                ++currEvent;
            }
            while (!pq.empty() && pq.top()[1] < day)
                pq.pop();

            if (!pq.empty())
            {
                pq.pop();
                res++;
            }
        } //for

        return res;
    }
};
// @lc code=end
//[[1,2],[2,3],[3,4],[1,2]]
//[1,2], [1,2], [2,3], [3,4]
// pq : [1,2], [2,3]
// day = 2
