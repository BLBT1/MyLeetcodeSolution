/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> res;
        const int n = words.size();
        int idx = 0;

        // outer loop
        while (idx < n)
        {
            // total num of char so far
            // add in the first word
            int totalChars = words[idx].size();
            int last = idx + 1; // where the last word is

            while (last < n)
            {
                if (totalChars + 1 + words[last].size() > maxWidth)
                    break;
                totalChars += 1 + words[last].size();
                last++;
            }

            int gaps = last - idx - 1;
            string s = "";

            if (last == n || gaps == 0)
            {
                for (int i = idx; i < last; ++i)
                {
                    s += words[i];
                    s.push_back(' ');
                }
                s.pop_back();
                while (s.size() < maxWidth)
                {
                    s.push_back(' ');
                }
            }
            else
            {
                int spaces = (maxWidth - totalChars) / gaps;
                int rest = (maxWidth - totalChars) % gaps;

                for (int i = idx; i < last - 1; i++)
                {
                    s += words[i];
                    s.push_back(' ');
                    for (int j = 0; j < spaces + (i - idx < rest ? 1 : 0); j++)
                    {
                        s.push_back(' ');
                    }
                }
                s += words[last - 1];
            }

            res.push_back(s);
            idx = last;
        } //while

        return res;
    }
};

// @lc code=end
