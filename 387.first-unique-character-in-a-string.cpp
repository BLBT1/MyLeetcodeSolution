/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        const int n = s.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; ++i)
        {
            cnt[s[i]]++;
        }
        for (int j = 0; j < n; ++j)
        {
            if (cnt[s[j]] == 1)
                return j;
        }
        return -1;
    }
};
// @lc code=end
