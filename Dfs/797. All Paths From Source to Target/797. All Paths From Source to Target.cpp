class Solution {
    unordered_map<int, int> adj;
    vector<vector<int>> res;
    vector<vector<int>> graph;
    int n;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        const int n = graph.size();
        this->n = n;
        this->graph = graph;
        vector<int> currPath = {0};
        dfs(currPath, 0);
        return res;
    }
    
    void dfs(vector<int> &currPath, int curr)
    {
        if(curr == n-1) 
        {
            res.push_back(currPath);
            return;
        }
        for(auto next: graph[curr])
        {
            currPath.push_back(next);
            dfs(currPath, next);
            currPath.pop_back();
        }
    }
};