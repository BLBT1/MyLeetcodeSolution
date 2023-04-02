class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s == "")
            return 0;
        int l = 0, r = 0;
        int res = 1;
        unordered_map<char, int> last_appear; // last position where is char appears
        for (; r < s.size(); ++r)
        {
            if (last_appear.find(s[r]) != last_appear.end())
            {
                // core step
                l = max(l, last_appear[s[r]] + 1);
            }
            last_appear[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
