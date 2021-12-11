/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        stringstream ss(s);
        string res;
        string word;
        while (ss >> word)
        {
            reverse(word.begin(), word.end());
            res += word;
            res += " ";
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
