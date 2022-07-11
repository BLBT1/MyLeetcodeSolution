class Solution
{
    int m = 0;
    int n = 0;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        // reverse process: we start do search from the ocean (four sides)
        m = heights.size();
        n = heights[0].size();

        // use two d vec to determine if (i,j) is touching pac or atl
        vector<vector<bool>> toPac(m, vector<bool>(n, false));
        vector<vector<bool>> toAtl(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i)
        {
            dfs(heights, toPac, i, 0);
            dfs(heights, toAtl, i, n - 1);
        }

        for (int j = 0; j < n; ++j)
        {
            dfs(heights, toPac, 0, j);
            dfs(heights, toAtl, m - 1, j);
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (toPac[i][j] && toAtl[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &canReach, int i, int j)
    {
        // if already can reach ocean, no need to keep going
        if (canReach[i][j] == true)
            return;

        canReach[i][j] = true;
        for (auto d : dir)
        {
            int a = i + d.first;
            int b = j + d.second;
            if (a >= 0 && b >= 0 && a < m && b < n && heights[i][j] <= heights[a][b])
            {
                dfs(heights, canReach, a, b);
            }
        }
    }
};
