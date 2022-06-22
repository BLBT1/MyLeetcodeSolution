class Solution
{
public:
    string countOfAtoms(string s)
    {
        stack<map<string, int>> stk;
        map<string, int> curr;

        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            if (ch == '(')
            {
                stk.push(curr);
                curr.clear();
            }
            else if (ch == ')')
            {
                // check if it follows a num
                int j = i + 1;
                while (j < s.size() && isdigit(s[j]))
                    ++j;
                int time = (i + 1 == j) ? 1 : stoi(s.substr(i + 1, j - i - 1));
                i = j - 1;
                for (auto p : curr)
                {
                    curr[p.first] = curr[p.first] * time;
                }
                for (auto p : stk.top())
                {
                    curr[p.first] += p.second;
                }
                stk.pop();
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                int j = i + 1;
                while (j < s.size() && s[j] >= 'a' && s[j] <= 'z')
                    ++j;
                string elt = s.substr(i, j - i);
                i = j - 1;
                // check if it follows a num
                j = i + 1;
                while (j < s.size() && isdigit(s[j]))
                    ++j;
                int time = (i + 1 == j) ? 1 : stoi(s.substr(i + 1, j - i - 1));
                curr[elt] += time;
                i = j - 1;
            }
        }

        string res = "";
        for (auto p : curr)
        {
            if (p.second == 1)
                res += p.first;
            else
            {
                res += p.first;
                res += to_string(p.second);
            }
        }
        return res;
    }
};