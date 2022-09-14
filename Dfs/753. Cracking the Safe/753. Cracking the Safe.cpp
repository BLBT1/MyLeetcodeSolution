class Solution
{
    string res;
    unordered_set<string> visited; // all visited
public:
    string crackSafe(int n, int k)
    {
        // initialize res to the first possible password
        for (int i = 0; i < n; ++i)
            res.push_back('0');

        visited.insert(res);

        if (dfs(n, k))
            return res;
        return "";
    }

    bool dfs(int n, int k)
    {
        if (visited.size() == pow(k, n))
            return true;

        for (char c = '0'; c < k + '0'; ++c)
        {
            string node = res.substr(res.size() - n, n);
            res.push_back(c);
            if (visited.find(res.substr(res.size() - n, n)) == visited.end())
            {
                visited.insert(res.substr(res.size() - n, n));
                if (dfs(n, k))
                    return true;
                visited.erase(res.substr(res.size() - n, n));
            }
            res.pop_back();
        }
        return false;
    }
};
