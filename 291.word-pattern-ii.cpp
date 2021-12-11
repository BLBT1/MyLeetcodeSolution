class Solution
{
    // for bijective mapping, need two maps
    unordered_map<char, string> map1;
    unordered_map<string, char> map2;

public:
    bool wordPatternMatch(string pattern, string s)
    {
        int curr = 0;
        int currInPat = 0;
        return dfs(pattern, s, curr, currInPat);
    }

    bool dfs(string &pattern,
             string &s,
             int curr, int currInPat)
    {
        if (curr == s.size() &&
            currInPat == pattern.size())
            return true;
        char ch = pattern[currInPat];
        if (map1.find(ch) != map1.end())
        {
            string t = map1[ch];
            if (curr + t.size() > s.size())
                return false;
            if (s.substr(curr, t.size()) != t)
                return false;
            return dfs(pattern, s, curr + t.size(), currInPat + 1);
        }
        else
        {
            char ch = pattern[currInPat];
            for (int i = curr; i < s.size(); ++i)
            {
                string t = s.substr(curr, i - curr + 1);
                if (map2.find(t) != map2.end())
                    continue;
                map2[t] = ch;
                map1[ch] = t;
                if (dfs(pattern, s, curr + t.size(), currInPat + 1))
                    return true;
                map1.erase(ch);
                map2.erase(t);
            } //for
        }
        return false;
    }
};