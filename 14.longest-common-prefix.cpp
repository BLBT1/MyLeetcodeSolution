/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        int minlen = 201;
        int n = strs.size();
        for (auto &s : strs)
        {
            minlen = min(minlen, (int)s.size());
        }
        for (int i = 0; i < minlen; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (strs[j][i] != strs[0][i])
                    return prefix;
            }
            prefix.push_back(strs[0][i]);
        }

        return prefix;
    }
};
// @lc code=end
