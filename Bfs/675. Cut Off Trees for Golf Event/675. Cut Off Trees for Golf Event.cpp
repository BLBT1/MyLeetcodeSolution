class Solution
{
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int m = 0;
    int n = 0;

public:
    int cutOffTree(vector<vector<int>> &forest)
    {
        m = forest.size();
        n = forest[0].size();
        map<int, pair<int, int>> mp;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (forest[i][j] > 1)
                    mp[forest[i][j]] = {i, j};
            }
        }

        int res = 0;
        int x = 0;
        int y = 0;
        for (auto &p : mp)
        {
            auto i = p.second.first;
            auto j = p.second.second;
            int step = bfs(x, y, i, j, forest);
            if (step == -1)
                return -1;
            res += step;
            x = i;
            y = j;
        }

        return res;
    }

    int bfs(int x, int y, int i, int j, vector<vector<int>> &grid)
    {
        if (x == i && y == j)
            return 0;
        queue<pair<int, int>> q;
        q.push({x, y});
        int step = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[x][y] = true;
        while (!q.empty())
        {
            int len = q.size();
            for (int k = 0; k < len; ++k)
            {
                auto curr = q.front();
                q.pop();
                if (curr.first == i && curr.second == j)
                    return step;

                for (auto &d : dir)
                {
                    int a = curr.first + d.first;
                    int b = curr.second + d.second;
                    if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] != 0 && visited[a][b] == false)
                    {
                        visited[a][b] = true;
                        q.push({a, b});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
