class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        // time: O(n + nlogn) = O(nlogn)
        // space: O(n)
        // make graph(adj list)
        unordered_set<int> visited; // set with all nodes that has been visited
        unordered_map<int, unordered_set<int>> adj;
        for (auto &e : edges)
        {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        return dfs(0, -1, adj, visited) && visited.size() == n;
    }

    // we must pass parent as a para because we don't want to go back in the graph
    bool dfs(int curr, int parent,
             unordered_map<int, unordered_set<int>> &adj,
             unordered_set<int> &visited)
    {
        if (visited.find(curr) != visited.end())
            return false;
        visited.insert(curr);

        for (auto v2 : adj[curr])
        {
            if (parent != v2)
            {
                if (!dfs(v2, curr, adj, visited))
                    return false;
            }
        }
        return true;
    }
};

// make an adj list from edges
// tree by definition is a connected graph without cycle