class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        // bucket sort
        unordered_map<string, int> mp;
        for (auto w : words)
        {
            mp[w]++;
        }

        int max_frq = 0;
        for (auto p : mp)
        {
            if (p.second > max_frq)
            {
                max_frq = p.second;
            }
        }
        vector<vector<string>> bucket(max_frq + 1, vector<string>());

        for (auto p : mp)
        {
            bucket[p.second].push_back(p.first);
        }

        for (auto &b : bucket)
        {
            sort(b.begin(), b.end());
        }

        vector<string> res;
        int cnt = 0;
        int flag = 0;
        for (int i = max_frq; i >= 0; i--)
        {
            for (auto w : bucket[i])
            {
                res.push_back(w);
                ++cnt;
                if (cnt == k)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        return res;
    }
};