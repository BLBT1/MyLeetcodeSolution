class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> mp;
        for (auto cp : cpdomains)
        {
            int j = cp.find(" ");
            int cnt = stoi(cp.substr(0, j));

            int i = j + 1;
            mp[cp.substr(i)] += cnt;
            while (j != -1)
            {
                j = cp.find(".", i);
                if (j == -1)
                    break;
                string domain = cp.substr(j + 1);
                mp[domain] += cnt;
                i = j + 1;
            }
        }
        vector<string> res;
        for (auto p : mp)
        {
            string ans = to_string(p.second) + " " + p.first;
            res.push_back(ans);
        }
        return res;
    }
};
