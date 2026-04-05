The problem is the same as return all the child of a given node for a tree

We could use dfs with mak of if the target has seen

```c++
class Solution {
    vector<int> res;
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();

        unordered_map<int, vector<int>> adj;
        unordered_map<int, bool> isRoot;
        for(int i = 0; i < n; ++i){
            isRoot[pid[i]] = true;
        }

        for (int i = 0; i < n; ++i) {
            adj[ppid[i]].push_back(pid[i]);
            isRoot[pid[i]] = false;
        }

        int root = 0;
        for(auto p: isRoot){
            if (p.second){
                root = p.first;
                break;
            }
        }

        dfs(root, kill, adj, false);

        return res;
    }

    void dfs(int curr, int kill, unordered_map<int, vector<int>> &adj, bool hasSeen){
        if(curr == kill){
            hasSeen = true;
        }
        if(hasSeen){
            res.push_back(curr);
        }

        for(auto next: adj[curr]){
            dfs(next, kill, adj, hasSeen);
        }
    }
};
```

traversal can start from kill with either dfs or bfs
```c++
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> & adj, vector<int> &result, int curr) {
        result.push_back(curr);

        for(int next : adj[curr]) {
            dfs(adj, result, next);
        }
    }

    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        unordered_map<int, vector<int>> adj;
        vector<int> result;

        for(int i = 0; i < pid.size(); i++) {
            adj[ppid[i]].push_back(pid[i]);
        }    

        dfs(adj, result, kill);
        return result;
    }
};
```



