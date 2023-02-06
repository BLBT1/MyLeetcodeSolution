class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        if (m < n)
            return {};
        vector<int> s_mp(26, 0);
        vector<int> p_mp(26, 0);
        for (auto c : p)
            p_mp[c - 'a'] += 1;

        vector<int> res;
        for (int i = 0; i < m; ++i)
        {
            if (i < n)
            {
                s_mp[s[i] - 'a'] += 1;
            }
            else
            {
                s_mp[s[i - n] - 'a'] -= 1;
                s_mp[s[i] - 'a'] += 1;
            }

            if (s_mp == p_mp)
                res.push_back(i - n + 1);
        }
        return res;
    }
};