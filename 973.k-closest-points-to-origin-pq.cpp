/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> pq;

        for (auto &pos : points)
        {
            int disSquare = pos[0] * pos[0] + pos[1] * pos[1];
            pq.push({disSquare, pos[0], pos[1]});
        }

        vector<vector<int>> res;
        for (int i = 0; i < k; ++i)
        {
            if (pq.empty())
                return res;
            res.push_back({(int)pq.top()[1], (int)pq.top()[2]});
            pq.pop();
        }

        return res;
    }
};
// @lc code=end
