class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // O(nlogn)
        // greedy:
        // to feed most kids
        // first we want to feed the kids that require less cookies
        // we want to first use less cookie to feed
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        int i = 0;
        int j = 0;
        while (i < g.size() && j < s.size())
        {
            if (g[i] <= s[j])
            {
                // we can feed the ith child with j th cookie
                ++j;
                ++i;
                cnt++;
            }
            else
            {
                // we cannot feed ith child with jth cookie, need to try to feed the child with more cookie
                ++j;
            }
        }
        return cnt;
    }
};
