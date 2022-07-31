class Solution
{
    int n;

public:
    bool canReach(vector<int> &arr, int start)
    {
        n = arr.size();
        vector<bool> visited(n, false);
        return dfs(arr, visited, start);
    }

    bool dfs(vector<int> &arr, vector<bool> &visited, int curr)
    {
        if (arr[curr] == 0)
            return true;
        visited[curr] = true;
        if (curr + arr[curr] >= 0 && curr + arr[curr] < n && visited[curr + arr[curr]] != true)
            if (dfs(arr, visited, curr + arr[curr]))
                return true;
        if (curr - arr[curr] >= 0 && curr - arr[curr] < n && visited[curr - arr[curr]] != true)
            if (dfs(arr, visited, curr - arr[curr]))
                return true;

        return false;
    }
};