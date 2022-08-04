class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        uordered_map<string, vector<string>> mp;
        vector<vector<string>> res;
        for (auto w : strs)
        {
            auto s = w;
            sort(s.begin(), s.end());
            mp[s].push_back(w);
        }

        for (auto p : mp)
        {
            res.push_back(p.second);
        }
        return res;
    }
};