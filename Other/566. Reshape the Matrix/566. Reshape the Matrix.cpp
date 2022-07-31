class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c)
            return mat;
        vector<vector<int>> res(r, vector<int>(c, 0));
        int total = m * n;
        for (int i = 0; i < total; ++i)
        {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};
// 3/1 = 3/