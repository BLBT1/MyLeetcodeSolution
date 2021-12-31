/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start
class Solution
{
    bool flag = false;

public:
    bool canReach(vector<int> &arr, int start)
    {
        const int n = arr.size();
        vector<bool> visited(n, false);
        dfs(arr, visited, start);
        return flag;
    }

    void dfs(vector<int> &arr, vector<bool> &visited, int curr)
    {
        if (arr[curr] == 0)
        {
            flag = true;
            return;
        }
        if (curr + arr[curr] < arr.size() && !visited[curr + arr[curr]])
        {
            visited[curr + arr[curr]] = true;
            dfs(arr, visited, curr + arr[curr]);
            visited[curr + arr[curr]] = false;
        }

        if (curr - arr[curr] >= 0 && !visited[curr - arr[curr]])
        {
            visited[curr - arr[curr]] = true;
            dfs(arr, visited, curr - arr[curr]);
            visited[curr - arr[curr]] = false;
        }
    }
};
// @lc code=end
