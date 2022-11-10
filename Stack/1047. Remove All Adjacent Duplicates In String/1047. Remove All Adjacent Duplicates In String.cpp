class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> stk;
        for (auto c : s)
        {
            if (!stk.empty() && stk.top() == c)
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }

        string res;
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};