class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        // use stack because if we have any left para leftover
        // we want to know want the index of them
        // so we should use stack
        stack<int> Stack; // record the position of
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                Stack.push(i);
            else if (s[i] == ')')
            {
                if (Stack.empty())
                    s[i] = '#';
                else
                    Stack.pop();
            }
        }

        while (!Stack.empty())
        {
            s[Stack.top()] = '#';
            Stack.pop();
        }

        string res = "";
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '#')
                res.push_back(s[i]);
        }
        return res;
    }
};