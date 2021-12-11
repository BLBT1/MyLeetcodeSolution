/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        const int n = s.size();
        vector<int> map(26, 0);

        for (int i = 0; i < n; ++i)
        {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }

        for (int j = 0; j < 26; ++j)
        {
            if (map[j] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
