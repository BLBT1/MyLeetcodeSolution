class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        unordered_map<char, int> cnt;
        unordered_set<char> visited;
        for (int i = 0; i < s.size(); ++i)
        {
            cnt[s[i]]++;
        }
        stack<char> stk;

        for (int i = 0; i < s.size(); ++i)
        {
            if (visited.find(s[i]) == visited.end())
            {
                while (!stk.empty() && stk.top() > s[i] && cnt[stk.top()] > 0)
                {
                    visited.erase(stk.top());
                    stk.pop();
                }
                visited.insert(s[i]);
                stk.push(s[i]);
            }
            cnt[s[i]]--;
        }

        string res = "";
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// s = "cbacdcbc"
// {a:0, b:0, c:0, d:0}
// visited: a
// increasing stack: acdb
