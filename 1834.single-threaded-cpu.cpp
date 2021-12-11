/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        typedef long long LL;
        typedef pair<LL, LL> PLL;

        for (int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);

        sort(tasks.begin(), tasks.end());
        priority_queue<PLL, vector<PLL>, greater<>> pq;

        LL cur = 0;
        vector<int> res;
        for (int i = 0; i < tasks.size(); i++)
        {
            while (cur < tasks[i][0] && !pq.empty())
            {
                res.push_back(pq.top().second);
                cur += pq.top().first;
                pq.pop();
            }

            pq.push({tasks[i][1], tasks[i][2]});
            cur = max(cur, (LL)tasks[i][0]);
        }

        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            cur += pq.top().first;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
