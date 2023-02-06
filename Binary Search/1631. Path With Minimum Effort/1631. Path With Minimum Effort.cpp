class Solution
{
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int low = 0;
        int hi = 1e6;
        while (low < hi)
        {
            int mid = low + (hi - low) / 2;
            if (canWalk(heights, mid))
                hi = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    bool canWalk(vector<vector<int>> &heights, int diff)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();
            if (x == m - 1 && y == n - 1)
                return true;
            for (auto d : dirs)
            {
                int i = x + d.first;
                int j = y + d.second;
                if (i < 0 || i >= m || j < 0 || j >= n)
                    continue;
                if (visited[i][j])
                    continue;
                if (abs(heights[i][j] - heights[x][y]) > diff)
                    continue;
                visited[i][j] = true;
                q.push({i, j});
            }
        }
        return false;
    }
};