### Brute force
First, find all the points where are 1s, then traversal over m*n for to update all manhattan distances
- T  = O(M*N*K), where k is the number of 1s. But the problem is if all cells are 1s, the k = M*N ==> TLE

### median theorem
We can find the pattern by observing one row only.

if two 1s
[1,0,0,0,0,1] --> all points are best points

if three 1s
[1,0,0,1,1] ---> the middle 1 is the best point, because the person at middle 1 don't need to travel

if four 1s 
[1,0,1,1,0,0,1] -> any of the two middle 1s are the best

**To generalize this pattern -- the best point is the median position of all 1s**

### Note: in this problem, we only care about 1s, so only need to store 1s

### Algorithm
- for all of rows, find x as median of rows of 1s
- for all of cols, find y as median of colls of 1s 
- (x,y) is the best point, calculate its manhattan distance


```
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows;
        vector<int> cols;
        for(int i =0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == 1){
                    rows.push_back(i);
                    cols.push_back(j);
                } 

        // rows are already sorted, need to sort cols
        sort(cols.begin(), cols.end());

        int res = 0;
        int x = rows[rows.size()/2];
        int y = cols[cols.size()/2];
        for(int i =0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(grid[i][j] == 1)
                    res += abs(x-i) + abs(y-j);

        return res;
    }
};
```





