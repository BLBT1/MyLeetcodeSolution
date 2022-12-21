class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        const int n = rooms.size();
        vector<int> hasKey(n, 0);
        hasKey[0] = 1; // room 0 is not looked
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i)
        {
            if (!rooms[i].empty() && hasKey[i])
                dfs(rooms, visited, hasKey, i);
        }
        return visited.size() == n;
    }

    void dfs(vector<vector<int>> &rooms,
             unordered_set<int> &visited,
             vector<int> &hasKey,
             int curr)
    {
        if (visited.find(curr) != visited.end())
            return;
        visited.insert(curr);
        for (int next : rooms[curr])
        {
            hasKey[next] = true;
            dfs(rooms, visited, hasKey, next);
        }
    }
};