/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int res = 0;
        unordered_set<int> set;
        for (char c : s)
        {
            set.insert(c);
        }
        for (auto &c : set)
        {
            res = max(res, helper(s, k, c));
        }
        return res;
    }

    int helper(string &s, int k, char replace)
    {
        queue<int> q;
        int res = 0;
        int l = 0, r = 0;
        for (; r < s.size(); ++r)
        {
            if (s[r] != replace)
            {
                q.push(r);
            }
            if (q.size() > k)
            {
                l = q.front() + 1;
                q.pop();
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// do sliding window 26 times, each time only replace one char
// only replace A"ABAB"

// do sliding window 26 times, each time only replace one char
// only replace A"ABAB"

// @lc code=end
