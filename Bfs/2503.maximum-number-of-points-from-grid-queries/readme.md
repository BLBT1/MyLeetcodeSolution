My note:

BFS + PQ (like lc 778)

- large query result must include smaller query result, so we can sort the query to reduce bfs

- {val, x, y} pos in grid, this cannot be a q, need to be a pq
  because we are counting new cells when popping (otherwise bfs gonna stop),
  and we want to make sure smallest value of grid always be pop first

```c++
    priority_queue<vector<int>, vector<vector<int>>, greater()> q;
```

- the pos in the queue is not necessary already counted in the count, it could be element ready to be count
    - so we always push to q. We check if query > grid[pos] when popping, instead of pushing

- also this is not traditional bfs (not all pos in the queue has smaller than query, so don't want to pop all)
```c++
while(!q.empty() && q.top()[0] < query){

    // ...
    for(auto d: dir){
        // ...
        q.push({grid[nX][nY], nX, nY});
        visited[nX][nY] = true;
}
    
}
```

```c++
struct cmp{
      bool operator()(pair<int, int> &q1, pair<int, int> &q2) {
        return q1.first > q2.first;
    }
};

class Solution {
    vector<pair<int, int>> dir = {
        {0,1}, {1,0}, {-1, 0}, {0, -1}
    };
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        
        // pair -> {val, q_idx}
        // min heap, so greater val is front
        // this pq is not needed, sorting once is ok
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(int i = 0; i < queries.size(); ++i){
            pq.push({queries[i],i});
        }

        vector<int> res(queries.size(), 0);
        // {val, x, y} pos in grid, this cannot be a q, need to be a pq
        // because we are counting new cells when popping (otherwise bfs gonna stop),
        //  and we want to make sure smallest value of grid always be pop first
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        int count = 0;
        while(!pq.empty()){
            auto currQ = pq.top();
            pq.pop();
            int query = currQ.first;
            int idx = currQ.second;
            
            // ** only pop if top is smaller than query
            // do need to pop all (for(... i < len ....)) like traditional bfs
            while(!q.empty() && q.top()[0] < query){
                auto currPos = q.top();
                q.pop();
                count++;

                int currVal = currPos[0];
                int x = currPos[1];
                int y = currPos[2];
                for(auto d: dir){
                    int nX = x+d.first;
                    int nY = y+d.second;

                    if (nX < 0 || nX >= m || nY < 0 || nY >= n) continue;
                    
                    if (visited[nX][nY]) continue;

                    q.push({grid[nX][nY], nX, nY});
                    visited[nX][nY] = true;
                }
            }

            res[idx] = count;
        }

        return res;
    }
};

// point is largest number of cell
// if q[i] > grid[x][y] --> we can move forward
// need to know result for each query

// native way -> we always start from top left
// for each query, we start a new dfs/bfs from top left grid[0][0]
// this is slow because the big part of bfs has been repeatedly counted
// T = A*Q A-> largest area size , Q -> # of queries


// If the we could gradually increase the size of connected area
// need to sort the queries for that
// -> bfs + pq
// Input: grid = [
//     [1,2,3],
//     [2,5,7],
//     [3,5,1]],
// queries = [5,6,2] 
// -> [2, 5, 6]

// becaue each time the points is adding up, so the points need to stored from the previous query


```
