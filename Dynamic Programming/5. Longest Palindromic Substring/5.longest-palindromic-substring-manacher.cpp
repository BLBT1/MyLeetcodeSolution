/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int maxCenter = -1;
        int maxRight = -1;

        string t = "#";
        for (int i = 0; i < s.size(); ++i)
        {
            t.push_back(s[i]);
            t.push_back('#');
        }
        const int n = t.size();
        vector<int> P(n);

        for (int i = 0; i < n; ++i)
        {
            int r = 0;
            if (i <= maxRight)
            {
                int j = 2 * maxCenter - i;
                r = min(P[j], maxRight - i);
                while (i - r >= 0 && i + r < n && t[i - r] == t[i + r])
                {
                    r++;
                }
                P[i] = r - 1;
            }
            else
            {
                while (i - r >= 0 && i + r < n && t[i - r] == t[i + r])
                {
                    r++;
                }
                P[i] = r - 1;
            }

            //  update maxCenter, maxRight
            if (P[i] + i > maxRight)
            {
                maxRight = P[i] + i;
                maxCenter = i;
            }
        } //for
        int maxLen = -1;
        int center = -1;
        for (int i = 0; i < n; ++i)
        {
            if (P[i] > maxLen)
            {
                maxLen = P[i];
                center = i;
            }
        }

        return s.substr(center / 2 - maxLen / 2, maxLen);
    }
};

// @lc code=end
