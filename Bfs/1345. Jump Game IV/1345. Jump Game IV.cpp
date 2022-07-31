class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> valToIdx;
        for (int i = n - 1; i >= 0; --i)
        {
            valToIdx[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;
        int step = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto curr = q.front();
                q.pop();
                if (curr == n - 1)
                {
                    return step;
                }
                for (auto next : valToIdx[arr[curr]])
                {
                    if (visited[next] == false)
                    {

                        q.push(next);
                        visited[next] = true;
                    }
                }

                if (curr + 1 >= 0 && curr + 1 < n && visited[curr + 1] == false)
                {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                if (curr - 1 >= 0 && curr - 1 < n && visited[curr - 1] == false)
                {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                valToIdx.erase(arr[curr]);
            }
            step++;
        }

        return -1;
    }
};