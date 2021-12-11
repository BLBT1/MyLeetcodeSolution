/*
 * @lc app=leetcode id=1705 lang=cpp
 *
 * [1705] Maximum Number of Eaten Apples
 */

// @lc code=start
class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<>> pq;
        int res = 0; // nums of apple eaten
        int i = 0;   // date of today

        while (i < apples.size() || !pq.empty())
        {
            // throw rotton apples
            while (!pq.empty() && pq.top().first <= i)
                pq.pop();

            // push in new apples
            if (i < apples.size() && apples[i] > 0)
                pq.push({i + days[i], apples[i]});

            // eat apple
            if (!pq.empty())
            {
                auto pair = pq.top();
                pq.pop();
                res++;
                if (pair.second >= 2)
                    pq.push({pair.first, pair.second - 1});
            }
            i++;
        }

        return res;
    }
};
// @lc code=end
