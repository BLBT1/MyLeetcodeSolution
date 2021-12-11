/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// @lc code=start
class Solution
{
    // reorder so letter before digit
    // letter: sort by content, if content is the same, sort by id
    // digit: maintain relative order
    // {key, content}
    static bool comp(pair<string, string> &a, pair<string, string> &b)
    {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first < b.first;
    }

public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> digitLogs, res;
        vector<pair<string, string>> letterLogs;

        for (string &s : logs)
        {
            int i = 0;
            // find the pos of first ' '
            while (s[i] != ' ')
                ++i;

            if (isalpha(s[i + 1]))
                letterLogs.emplace_back(s.substr(0, i), s.substr(i + 1));
            else
                digitLogs.push_back(s);
        }

        sort(letterLogs.begin(), letterLogs.end(), comp);

        for (auto &p : letterLogs)
            res.push_back(p.first + " " + p.second);

        for (string &s : digitLogs)
            res.push_back(s);
        return res;
    }
};
// @lc code=end
