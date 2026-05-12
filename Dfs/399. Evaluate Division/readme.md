# 399. Evaluate Division

这个题其实是可以转化成一个graph的题目

- 比如说： a/b = 2, b/c = 3, 那 a/c 其实是 (a/b)*(b/c) = 2.3 = 6

- 可以转化为图： a-> = a->b->c

- 图中可能有分叉：

```
             ->b->d
            a->c->e
             ->g->w
```

此图中我们想找到　a/z，　也就是 a->z 的　路径，　那就需要用dfs

Time: O(E+E*Q), E is number of equation, Q is number of queries


这道题必须要记录已经visited到全部路径， 只记录parent是不够的
example
```
[["a","b"],["b","c"],["a","c"],["d","e"]]
[2.0,3.0,6.0,1.0]
[["a","c"],["b","c"],["a","e"],["a","a"],["x","x"],["a","d"]]
```
只记录parent到话会stack overflow on query ["a","e"]

a -> b -> c -> a 这样就有cycle了


```c++
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        for(int i = 0; i < n; ++i){
            auto e = equations[i];
            adj[e[0]].push_back({e[1], values[i]});
            adj[e[1]].push_back({e[0], 1/values[i]});
        }

        vector<double> res;
        unordered_set<string> visited;
        for(auto q: queries){
            if (adj.find(q[1]) == adj.end() || adj.find(q[0]) == adj.end())
                res.push_back(-1.0);
            else if(q[1] == q[0])
                res.push_back(1);
            else
                res.push_back(dfs(adj, visited, q[0], q[1]));
        }
        return res;
    }

    double dfs(unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string> &visited, string curr, string end){
        if(curr == end)
            return 1;
        
        if(adj.find(curr) == adj.end())
            return -1;

        for(auto nxt: adj[curr]) {
            string next = nxt.first;
            double val = nxt.second;

            if(visited.find(next) != visited.end())
                continue;

            visited.insert(next);
            double futureRes = dfs(adj, visited, next, end);
            visited.erase(next);
            if(futureRes != -1)
                return val*futureRes;
        }

        return -1;
    }
};
```
    
