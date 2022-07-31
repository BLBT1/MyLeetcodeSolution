class Solution
{
    // for bjective mapping
    unordered_map<char, string> mp1;
    unordered_map<string, char> mp2;

public:
    bool wordPatternMatch(string pattern, string s)
    {
        return dfs(0, 0, pattern, s);
    }

    bool dfs(int x, int y, string &pattern, string &s)
    {
        if (x == pattern.size() && y == s.size())
            return true;
        char ch = pattern[x];
        if (mp1.find(ch) != mp1.end())
        {
            string curr = mp1[ch];
            if (y + curr.size() > s.size())
                return false;
            if (s.substr(y, curr.size()) != curr)
                return false;
            return dfs(x + 1, y + curr.size(), pattern, s);
        }
        else
        {
            for (int end = y; end < s.size(); ++end)
            {
                string curr = s.substr(y, end - y + 1);
                if (mp2.find(curr) != mp2.end())
                    continue;
                mp1[ch] = curr;
                mp2[curr] = ch;
                if (dfs(x + 1, y + curr.size(), pattern, s))
                    return true;
                mp1.erase(ch);
                mp2.erase(curr);
            }
            return false;
        }
    }
};

// pattern [#]######
//          ch
//     s:  [##############
//         y
