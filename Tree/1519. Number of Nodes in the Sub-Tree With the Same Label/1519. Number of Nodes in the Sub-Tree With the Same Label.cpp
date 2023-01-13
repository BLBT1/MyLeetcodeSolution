class Solution
{
    unordered_map<int, vector<int>> adj;
    vector<int> visited;
    vector<int> res;
    int n = 0;
    string labels;

public:
    vector<int> countSubTrees(int n,
                              vector<vector<int>> &edges,
                              string labels)
    {
        // time : O(N)
        // space: O(N*k), k is the size of map for each subtree
        this->labels = labels;
        this->n = n;
        visited = vector<int>(n, 0);
        res = vector<int>(n, 0);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        visited[0] = 1;
        unordered_map<char, int> cnt;
        dfs(0, cnt);

        return res;
    }

    void dfs(int curr, unordered_map<char, int> &cnt)
    {
        if (curr >= n)
            return;

        // 每一个点都会为自己的subtree创造一个map
        // 同时也会拿到parent 传下来的map
        // 用dfs把自己subtree的个数统计完后，要把统计结果加进parent传下来的map里去
        for (auto next : adj[curr])
        {
            unordered_map<char, int> cnt1;

            if (visited[next] == 1)
                continue;
            visited[next] = 1;
            dfs(next, cnt1);

            for (auto p : cnt1)
                cnt[p.first] += p.second;
        }

        char currLabel = labels[curr];
        cnt[currLabel]++;
        res[curr] = cnt[currLabel];
    }
};