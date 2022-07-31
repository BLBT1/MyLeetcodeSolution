class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (auto c : s)
        {
            mp[c]++;
        }
        int res = 0;
        bool flag = false;
        for (auto p : mp)
        {
            if (p.second % 2 == 0)
                res += p.second;
            else
            {
                if (!flag)
                {
                    flag = true;
                    res += p.second;
                }
                else
                {
                    res += p.second / 2 * 2;
                }
            }
        }
        return res;
    }
};