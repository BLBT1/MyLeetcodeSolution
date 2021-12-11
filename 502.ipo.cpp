/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 */

// @lc code=start
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        const int n = profits.size();
        using nDoEntry = array<int, 2>; //{cap[i],i}

        priority_queue<nDoEntry,
                       vector<nDoEntry>,
                       greater<>>
            nDoPq;
        priority_queue<int, vector<int>, less<>> doPq;

        for (int i = 0; i < n; ++i)
        {
            nDoPq.push({capital[i], i});
        } //for

        int count = 0;

        while (count < k)
        {
            // move from do pq to ndopq
            while (!nDoPq.empty() && nDoPq.top()[0] <= w)
            {
                auto [cap, idx] = nDoPq.top();
                nDoPq.pop();
                doPq.push(profits[idx]);
            } //while

            if (!doPq.empty())
            {
                w += doPq.top();
                doPq.pop();
            }

            ++count;
        } //while

        return w;
    }
};
// @lc code=end
