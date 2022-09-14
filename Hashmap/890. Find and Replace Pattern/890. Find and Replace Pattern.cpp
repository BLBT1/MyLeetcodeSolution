class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words,
                                         string pattern)
    {
        vector<string> res;
        for (auto s : words)
        {
            if (isValid(s, pattern))
                res.push_back(s);
        }

        return res;
    }

    bool isValid(string &s, string &p)
    {
        if (s.size() != p.size())
            return false;

        int i = 0;
        unordered_map<char, char> mp1; // s->p
        unordered_map<char, char> mp2; // p->s
        while (i < s.size())
        {
            if (mp1.find(s[i]) != mp1.end() && mp2.find(p[i]) != mp2.end())
            {
                if (s[i] != mp2[p[i]])
                    return false;
                if (p[i] != mp1[s[i]])
                    return false;
            }
            else
            {
                if (mp1.find(s[i]) != mp1.end())
                    return false;
                if (mp2.find(p[i]) != mp2.end())
                    return false;

                mp1[s[i]] = p[i];
                mp2[p[i]] = s[i];
            }
            ++i;
        }

        return true;
    }
};