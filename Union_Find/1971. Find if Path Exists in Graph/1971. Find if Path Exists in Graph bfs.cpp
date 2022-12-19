class Solution {
public:
    bool validPath(int n,
                   vector<vector<int>>& edges,
                   int src,
                   int dest)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> visited(n, 0);
        for(auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(src);
        visited[src] = 1;
        while(!q.empty())
        {
            int len = q.size();
            for(int k = 0; k < len; ++k)
            {
                auto curr = q.front();
                q.pop();
                if(curr == dest)
                    return true;
                
                for(auto next: adj[curr])
                {
                    if(visited[next] == 1)
                        continue;
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
        return false;
    }
};