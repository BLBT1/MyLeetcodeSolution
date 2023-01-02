class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        s = s + " ";
        unordered_map<string, char> stoc;
        unordered_map<char, string> ctos;
        int i = 0;
        int j = 0;
        int m = pattern.size();
        int n = s.size();
        while (i < m && j < n)
        {
            int k = s.find(" ", j);
            string w = s.substr(j, k - j);
            if (ctos.count(pattern[i]) != stoc.count(w))
                return false;

            if (ctos.find(pattern[i]) == ctos.end())
            {
                ctos[pattern[i]] = w;
                stoc[w] = pattern[i];
            }
            if (ctos[pattern[i]] != w || stoc[w] != pattern[i])
                return false;
            ++i;
            j = k + 1;
        }
        if (i < m || j < n)
            return false;
        return true;
    }
};
