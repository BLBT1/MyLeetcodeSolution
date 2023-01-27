class Solution
{
    using VI = array<int, 3>;

public:
    int findCheapestPrice(int n,
                          vector<vector<int>> &flights,
                          int src,
                          int dst,
                          int k)
    {
        // 对于图中每个点， 我们要当作一个二维量，<node, times>
        //  times 是做了几次飞机到了这个点
        //  为什么要这样?
        //  举个例子， 如左边，0->node 1 第一次访问只是再当前的times下的最优解，
        //  但是不是 所有次数的， 所以要对于每个访问次数都要更新，而不是一次访问就结束了
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<VI, vector<VI>, greater<>> pq;
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));
        pq.push({0, src, 0});
        while (!pq.empty())
        {
            int c = pq.top()[0];
            int curr = pq.top()[1];
            int t = pq.top()[2];
            pq.pop();

            if (curr == dst)
                return c;
            if (t >= k + 1)
                continue;
            if (cost[curr][t] < INT_MAX)
                continue; // has already find best cost for this point at this time
            cost[curr][t] = c;
            for (auto next : adj[curr])
            {
                int x = next.first;
                int p = next.second;
                if (cost[x][t + 1] < INT_MAX)
                    continue;
                pq.push({c + p, x, t + 1});
            }
        }
        return -1;
    }
};