class Solution
{
    unordered_map<int, vector<int>> adj;
    vector<int> subtree;
    vector<int> visited;
    vector<int> dist_from0;
    vector<int> res;
    int n;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        subtree = vector<int>(n, 0);
        visited = vector<int>(n, 0);
        dist_from0 = vector<int>(n, 0);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // find subtree size for each node
        visited[0] = 1;
        find_subtree_size(0);

        // find dist_sum for root 0 as a tree
        for (auto &i : visited)
            i = 0;
        visited[0] = 1;
        find_dist_from_src(0, 0, 0);
        int sumdist0 = 0;
        for (auto i : dist_from0)
        {
            sumdist0 += i;
        }

        // update sum dist for each root
        res = vector<int>(n, 0);
        res[0] = sumdist0;
        for (auto &i : visited)
            i = 0;
        visited[0] = 1;
        dfs(0);
        return res;
    }

    int find_subtree_size(int root)
    {
        int sum = 1;
        for (int next : adj[root])
        {
            if (visited[next] == 1)
                continue;
            visited[next] = 1;
            sum += find_subtree_size(next);
        }
        subtree[root] = sum;
        return sum;
    }

    void find_dist_from_src(int src, int curr, int dist)
    {
        dist_from0[curr] = dist;
        for (int next : adj[curr])
        {
            if (visited[next] != 1)
            {
                visited[next] = 1;
                find_dist_from_src(src, next, dist + 1);
            }
        }
    }

    void dfs(int curr)
    {
        for (int next : adj[curr])
        {
            if (visited[next] == 1)
                continue;
            visited[next] = 1;
            res[next] = res[curr] + n - 2 * subtree[next];
            dfs(next);
        }
    }
};