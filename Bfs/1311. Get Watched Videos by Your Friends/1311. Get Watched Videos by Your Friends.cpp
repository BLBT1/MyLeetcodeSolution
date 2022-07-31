class Solution
{
    struct mycmp
    {
        bool operator()(pair<string, int> a, pair<string, int> b)
        {
            if (a.second != b.second)
                return a.second < b.second;
            else
                return a.first < b.first;
        }
    };

public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos,
                                          vector<vector<int>> &friends, int id, int level)
    {
        int n = friends.size();
        queue<int> q;
        q.push(id);
        vector<bool> visited(n, false);
        visited[id] = true;
        int lv = 0;
        unordered_map<string, int> cnt;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; ++i)
            {
                auto curr = q.front();
                q.pop();
                for (auto mv : watchedVideos[curr])
                {
                    cnt[mv]++;
                }

                for (auto fr : friends[curr])
                {
                    if (visited[fr] == false)
                    {
                        visited[fr] = true;
                        q.push(fr);
                    }
                }
            }
            if (lv == level)
                break;
            lv++;
            cnt.clear();
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, mycmp> pq;
        for (auto p : cnt)
        {
            pq.push(p);
        }

        vector<string> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};