/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        int res = 0;
        for (int m = 1; m <= 26; ++m)
        {
            res = max(res, helper(s, m, k));
        }
        return res;
    }

    int helper(string &s, int m, int k)
    {
        // 固定左指针，探索右指针
        // count the occurance of each char
        unordered_map<char, int> Map;
        int res = 0;
        int l = 0, r = 0;
        int cnt = 0; // cnt the number of char with more than k occurance
        for (; l < s.size(); ++l)
        {
            while (r < s.size() && Map.size() <= m)
            {
                Map[s[r]]++;
                if (Map[s[r]] == k)
                {
                    cnt++;
                }

                if (Map.size() == m && cnt == m)
                {
                    res = max(res, r - l + 1);
                }
                ++r;
            }
            Map[s[l]]--;
            if (Map[s[l]] == k - 1)
            {
                cnt--;
            }
            if (Map[s[l]] == 0)
            {
                Map.erase(s[l]);
            }
        }
        return res;
    }
};
// @lc code=end
