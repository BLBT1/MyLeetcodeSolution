class Solution
{
    unordered_map<string, vector<string>> mp;
    vector<string> res;

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        sort(tickets.rbegin(), tickets.rend());
        for (auto p : tickets)
        {
            mp[p[0]].push_back(p[1]);
        }

        return dfs("JFK");
    }

    vector<string> dfs(string curr)
    {
        vector<vector<string>> paths;

        // path1: path goes to end, but still some edges in the graph have not been walked though
        // path2: the Eulerian circuit after move the path that visited
        while (mp[curr].size() > 0)
        {
            // we have another path which goes back to the curr node
            string next = mp[curr].back();
            mp[curr].pop_back();
            paths.push_back(dfs(next));
        }

        vector<string> res;
        res.push_back(curr);
        // path2 need to go first then path1
        for (int i = paths.size() - 1; i >= 0; --i)
        {
            for (auto s : paths[i])
            {
                res.push_back(s);
            }
        }
        return res;
    }
};