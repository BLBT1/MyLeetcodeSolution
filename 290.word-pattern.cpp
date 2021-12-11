/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        stringstream ss(s);
        int i = 0;
        string next;
        while (ss >> next)
        {
            if (i > pattern.size())
                return false;

            if (map1.find(pattern[i]) != map1.end())
            {
                if (next != map1[pattern[i]])
                    return false;
            }
            else if (map2.find(next) != map2.end())
            {
                if (pattern[i] != map2[next])
                    return false;
            }
            else
            {
                map1[pattern[i]] = next;
                map2[next] = pattern[i];
            }

            ++i;
        }

        if (i != pattern.size())
            return false;

        return true;
    }
};
// @lc code=end
