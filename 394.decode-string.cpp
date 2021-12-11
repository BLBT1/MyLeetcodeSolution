/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        const int n = s.size();
        stack<int> times;
        stack<string> strs;
        int i = 0;
        string curr = "";

        while (i < n)
        {
            if (isdigit(s[i]))
            {
                int j = i;
                while (isdigit(s[j]))
                    ++j;
                int num = stoi(s.substr(i, j - i));
                times.push(num);
                i = j;
                // now i is on '[' for sure
                strs.push(curr);
                curr = "";
            }
            else if (isalpha(s[i]))
            {
                curr.push_back(s[i]);
            }
            else if (s[i] == ']')
            {
                string temp = curr;
                int num = times.top();
                times.pop();
                for (int k = 0; k < num - 1; ++k)
                    curr += temp;
                curr = strs.top() + curr;
                strs.pop();
            }
            ++i;
        }

        return curr;
    }
};
// @lc code=end

// s = "10[a][a2[caa]]"
//s : while isdigits
// int num = 10;
// [ -> in stack+ append cur to res
// ] -> out stack
// times: 1,
// strs:  a,
// cur 1*[2*c+a]
// res: a*10
// natural to think of using a stack