class Solution
{
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        set<pair<int, int>> fresh;
        int time = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    fresh.insert({i, j});
                }
                else if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            int len = q.size();
            if (fresh.empty())
                return time;
            for (int i = 0; i < len; ++i)
            {
                auto rtn = q.front();
                q.pop();
                for (auto d : dir)
                {
                    int x = rtn.first + d.first;
                    int y = rtn.second + d.second;
                    if (fresh.find({x, y}) != fresh.end())
                    {
                        q.push({x, y});
                        fresh.erase({x, y});
                    }
                }
            }
            time++;
        }

        if (fresh.empty())
            return time;
        else
            return -1;
    }
};