/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> Table; // map {char, int} for t
        unordered_map<char, int> Map;   // map for our substr
        string res = "";
        int cnt = 0;
        int len = INT_MAX;
        for (char &c : t)
        {
            Table[c]++;
            // Map[c]++;
        }

        int M = Table.size();
        int l = 0, r = 0;
        int count = 0; // number of char
        for (; r < s.size(); ++r)
        {
            Map[s[r]]++;
            if (Map[s[r]] == Table[s[r]])
            {
                cnt++;
            }
            while (cnt == M)
            {
                string sub = s.substr(l, r - l + 1);
                if (sub.size() < len)
                {
                    res = sub;
                    len = sub.size();
                }
                Map[s[l]]--;
                if (Map[s[l]] == Table[s[l]] - 1)
                    cnt--;
                ++l;
            }
        }
        return res;
    }
};
// @lc code=end

// sub string of s must contains all the chars from t
//
