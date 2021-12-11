/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
class Solution
{
    // sort two workers by the unitWage
    static bool myCmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second * 1.0 / a.first < b.second * 1.0 / b.first;
    }

public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        // sort + pq
        // unitWage[i] = wage[i]/quality[i]
        vector<pair<int, int>> workers;
        double res = std::numeric_limits<double>::max();
        workers.reserve(wage.size());
        for (int i = 0; i < quality.size(); ++i)
            workers.push_back({quality[i], wage[i]});

        sort(workers.begin(), workers.end(), myCmp); // sort by unitWage asc.

        priority_queue<int, vector<int>, less<>> pq; // max heap for quality
        int sum_quality = 0;

        for (int i = 0; i < workers.size(); ++i)
        {
            sum_quality += workers[i].first;
            pq.push(workers[i].first);
            if (pq.size() > k)
            {
                sum_quality -= pq.top();
                pq.pop();
            }
            if (pq.size() == k)
            {
                double unitWage = workers[i].second * 1.0 / workers[i].first;
                res = min(res, unitWage * sum_quality);
            }

        } //for

        return res;
    }
};
// @lc code=end
