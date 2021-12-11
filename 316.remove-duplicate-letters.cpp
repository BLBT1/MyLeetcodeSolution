/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<int> Stack;               // mono inc.
        vector<bool> alpha(26, false);  // if any of apha has been used
        unordered_map<char, int> count; // total appearance of each char
        string res;

        // record count
        for (const auto ch : s)
            count[ch]++;

        // use monotonic stack
        for (int i = 0; i < s.size(); ++i)
        {
            // if used, never used again
            if (alpha[s[i] - 'a'] == true)
            {
                --count[s[i]];
            }
            else // if hasn't been used
            {
                while (!Stack.empty() &&
                       s[Stack.top()] >= s[i] &&
                       count[s[Stack.top()]] > 0)
                {
                    alpha[s[Stack.top()] - 'a'] = false;
                    Stack.pop();
                } //while
                Stack.push(i);
                alpha[s[i] - 'a'] = true;
                --count[s[i]];
            }
        } //for

        while (!Stack.empty())
        {
            res = s[Stack.top()] + res;
            Stack.pop();
        }

        return res;
    }
};
// @lc code=end
