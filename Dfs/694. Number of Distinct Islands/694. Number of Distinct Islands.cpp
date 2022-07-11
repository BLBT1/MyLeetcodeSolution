class Solution
{
    int m = 0;
    int n = 0;
    string currShape = "";
    unordered_set<string> st;

public:
    int numDistinctIslands(vector<vector<int>> &grid)
    {
        // how to use string to encode a shape? => use the direction of reach it
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    currShape = "";
                    dfs(i, j, 's', grid);
                    st.insert(currShape);
                }
            }
        }

        return st.size();
    }

    void dfs(int i, int j, char dir, vector<vector<int>> &grid)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = 2;
        currShape.push_back(dir);

        dfs(i, j + 1, 'r', grid);
        dfs(i + 1, j, 'd', grid);
        dfs(i, j - 1, 'l', grid);
        dfs(i - 1, j, 'u', grid);

        currShape.push_back('e');
    }
};