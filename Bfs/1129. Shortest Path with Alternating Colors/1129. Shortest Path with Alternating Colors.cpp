class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n,
                                         vector<vector<int>> &redEdges,
                                         vector<vector<int>> &blueEdges)
    {
        unordered_map<int, vector<int>> red;
        unordered_map<int, vector<int>> blue;
        for (auto re : redEdges)
            red[re[0]].push_back(re[1]);
        for (auto be : blueEdges)
            blue[be[0]].push_back(be[1]);

        vector<int> res(n, -1);
        queue<pair<int, int>> q; // {node, edge to that node: 0->red, 1->blue, 2->start}
        int dist = 0;
        q.push({0, 2});

        vector<bool> visited_from_red(n, false);
        vector<bool> visited_from_blue(n, false);
        visited_from_blue[0] = true;
        visited_from_red[0] = true;

        while (!q.empty())
        {
            int len = q.size();
            for (int k = 0; k < len; ++k)
            {
                int curr = q.front().first;
                int prevEdge = q.front().second;
                q.pop();
                if (res[curr] == -1)
                    res[curr] = dist;
                if (prevEdge == 0 || prevEdge == 2)
                {
                    // go to all the blue edge
                    for (auto next : blue[curr])
                    {
                        if (visited_from_red[next])
                            continue;
                        visited_from_red[next] = true;
                        q.push({next, 1});
                    }
                }
                if (prevEdge == 1 || prevEdge == 2)
                {
                    for (auto next : red[curr])
                    {
                        if (visited_from_blue[next])
                            continue;
                        visited_from_blue[next] = true;
                        q.push({next, 0});
                    }
                }
            }
            dist += 1;
        }
        return res;
    }
};