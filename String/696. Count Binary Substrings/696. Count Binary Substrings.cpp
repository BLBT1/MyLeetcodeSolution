class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int curr = 1; // num of consecutive current elt
        int prev = 0; // num of consecutive prev elt
        int res = 0;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                curr++;
            }
            else
            {
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        res += min(prev, curr);
        return res;
    }
};