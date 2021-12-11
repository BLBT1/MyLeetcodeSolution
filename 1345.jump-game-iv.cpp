/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

// @lc code=start
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        const int n = arr.size();
        if (n == 1)
            return 0;
        // greedy: we want to visit greater idx first
        unordered_map<int, priority_queue<int, vector<int>, less<>>> map;
        for (int i = 0; i < arr.size(); ++i)
            map[arr[i]].push(i);

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int step = 0;

        while (!q.empty())
        {
            step++;
            int len = q.size();
            for (int k = 0; k < len; ++k)
            {
                auto curr = q.front();
                q.pop();
                if (curr + 1 < n && !visited[curr + 1])
                {
                    if (curr + 1 == n - 1)
                        return step;
                    q.push(curr + 1);
                    visited[curr + 1] = true;
                }

                if (curr - 1 >= 0 && !visited[curr - 1])
                {
                    if (curr - 1 == n - 1)
                        return step;
                    q.push(curr - 1);
                    visited[curr - 1] = true;
                }

                while (!map[arr[curr]].empty())
                {
                    int i = map[arr[curr]].top();
                    map[arr[curr]].pop();
                    if (!visited[i])
                    {
                        if (i == n - 1)
                            return step;
                        q.push(i);
                        visited[i] = true;
                    }
                } //for
            }
        } //while

        return -1;
    }
};
// @lc code=end
