class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        // indexing + binary search
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); ++i)
            mp[s[i]].push_back(i);

        int cnt = 0;
        for (string w : words)
        {
            int pos = -1;
            int j = 0;
            for (; j < w.size(); ++j)
            {
                char c = w[j];
                auto itr = upper_bound(mp[c].begin(), mp[c].end(), pos);
                if (itr == mp[c].end())
                    break;
                pos = *itr;
            }
            if (j == w.size())
                cnt += 1;
        }
        return cnt;
    }
};