/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int count = 0;
        stack<char> Stack; // mono in.

        for (int i = 0; i < num.size(); ++i)
        {
            while (!Stack.empty() && Stack.top() > num[i] && count < k)
            {
                Stack.pop();
                ++count;
            } //while

            Stack.push(num[i]);
        } //for

        //what if now the count is less than k
        while (!Stack.empty() && count < k)
        {
            Stack.pop();
            ++count;
        } // while

        string res = "";

        // construct in the reverse order and reverse is faster
        while (!Stack.empty())
        {
            res += Stack.top();
            Stack.pop();
        }
        while (res.size() > 0 && res.back() == '0')
            res.pop_back();

        reverse(res.begin(), res.end());

        return res == "" ? "0" : res;
    }
};
// @lc code=end
