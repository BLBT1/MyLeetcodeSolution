/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Dijkstra
        unordered_map<int, vector<pair<int, int>>> graph; //{src, {time, next}}

        for (auto &t : times)
            graph[t[0]].push_back({t[2], t[1]});

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<>>
            pq; // min heap

        int res = 0;
        vector<bool> visited(n + 1, false);
        pq.push({0, k});
        int count = 0;

        while (!pq.empty())
        {
            auto [dis, curr] = pq.top();
            pq.pop();
            // idea: the first pop is the shortest path from k
            if (visited[curr])
                continue;
            count++;
            visited[curr] = true;
            res = max(res, dis);

            for (auto &next : graph[curr])
                pq.push({dis + next.first, next.second});
        } //while

        //cout << count << endl;
        if (count == n)
            return res;

        return -1;
    }
};
// @lc code=end
