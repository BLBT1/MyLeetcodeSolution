class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        unordered_map<int, int> cnt;
        for (int i = 0, j = 0; i < s.size(); ++i)
        {
            cnt[s[i]] += 1;
            while (j <= i && cnt[s[i]] > 1)
            {
                cnt[s[j]] -= 1;
                ++j;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};