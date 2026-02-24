
```c++
class Solution {
    unordered_map<int, vector<pair<int, int>>> adj;
    vector<int> res;
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        // we care about the both direction for edges
        for(auto e: edges){
            adj[e[0]].push_back({e[1],1});
            adj[e[1]].push_back({e[0],-1});
        }

        // find the first ans for a node
        int count0 = dfs1(0, -1);

        res = vector(n, 0);

        // re-root for find all ans
        dfs2(0, -1, count0);
        return res;
    }

    int dfs1(int curr, int parent){
        int res = 0;
        for(auto p: adj[curr]){
            int nxt = p.first;
            int dir = p.second;
            if(nxt == parent) continue;
            if (dir == 1){
                res += dfs1(nxt, curr);
            } else{
                res += 1+dfs1(nxt, curr);
            }
        }
        return res;
    }

    void dfs2(int curr, int parent, int count){
            res[curr] = count; 
            
            for(auto p: adj[curr]){
            int nxt = p.first;
            int dir = p.second;
            if(nxt == parent) continue;
            if (dir == 1){
                // after re-root, 顺边变成了逆边
                dfs2(nxt, curr, count+1);
            } else{
                dfs2(nxt, curr, count-1);
            }
        }
    }
};

// re-root
// first find an anwser for one root,
// say for example#1, 
// if we know the answer[2], we can reroot to get answer[1] (by +1 or -1 of edge reversals)
```


