/*
 * @lc app=leetcode id=1190 lang=cpp
 *
 * [1190] Reverse Substrings Between Each Pair of Parentheses
 */

// @lc code=start
class Solution
{

    stack<int> Stack; // store the pos of (
public:
    string reverseParentheses(string s)
    {
        // this solution is O(n^2)
        // 韩神解法 O（n）
        //https://github.com/wisdompeak/LeetCode/blob/master/Stack/1190.Reverse-Substrings-Between-Each-Pair-of-Parentheses/1190.Reverse-Substrings-Between-Each-Pair-of-Parentheses_O(N).cpp
        string res;
        for (auto ch : s)
        {
            if (isalpha(ch))
                res.push_back(ch);
            else if (ch == '(')
                Stack.push(res.size());
            else
            {
                int i = Stack.top();
                Stack.pop();
                reverse(res.begin() + i, res.end());
            }
        }
        return res;
    }
};
// @lc code=end
