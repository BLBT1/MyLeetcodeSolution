For each cell in the matrix, we can remember "start from this point, what's is the long increasing path length"

```c++
class Solution {
    vector<pair<int, int>> directions = { 
        {1,0}, {0,1}, {-1,0},{0,-1}
    };
    int res = 0;

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> maxFromCurr(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) {
                int currMax = dfs(matrix,maxFromCurr, i, j)+1;
                res = max(currMax, res);
            }

        return res;
    }

    // return max increasing path sum start from curr point
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &maxFromCurr,
                             int i, int j) { 
        int n = matrix.size();
        int m = matrix[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 0;

        if(maxFromCurr[i][j] != 0) {
            return maxFromCurr[i][j];
        }

        int localMax = 0;
        for (auto d: directions) {
            int _x = i+d.first;
            int _y = j+d.second;
            if (_x >= 0 && _x < n && _y >=0 && _y < m && matrix[_x][_y] > matrix[i][j]){
                int maxWithCurrDir = dfs(matrix, maxFromCurr, _x, _y)+1;
                localMax = max(maxWithCurrDir, localMax);
            }
        }
        maxFromCurr[i][j] = localMax;

        return localMax;
    }
};

// dfs()
// We can remember the longest increasing path from curr point
// 
```

