class Solution
{
public:
    int minimumTotal(vector<vector<int>> &tri)
    {
        int m = tri.size();
        if (m < 2)
            return tri[0][0];
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < tri[i].size(); ++j)
            {
                tri[i][j] = tri[i][j] + min(tri[i + 1][j], tri[i + 1][j + 1]);
            }
        }
        return tri[0][0];
    }
};

// 2
// 3 4
// 6 5 7
// 4 1 8 3