class Solution
{
public:
    int calculate(string s)
    {
        stack<string> evals;
        string currStr = "";
        for (auto ch : s)
        {
            if (ch == '(')
            {
                evals.push(currStr);
                currStr = "";
            }
            else if (ch == ')')
            {
                int val = eval(currStr);
                currStr = evals.top() + to_string(val);
                evals.pop();
            }
            else
            {
                currStr.push_back(ch);
            }
        }

        return eval(currStr);
    }

    int eval(string s)
    {
        s = "+" + s;
        // cout << s << endl;

        stack<int> nums;
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            if (ch == '+' || ch == '-')
            {
                int j = i + 1;
                if (s[j] == '+' || s[j] == '-')
                    j++;
                while (j < s.size() && isdigit(s[j]))
                    ++j;
                // cout << s.substr(i+1, j-i-1) <<endl;
                int num = stoi(s.substr(i + 1, j - i - 1));
                if (ch == '+')
                    nums.push(num);
                else
                    nums.push(-num);
                i = j - 1;
            }
            else if (ch == '*' || ch == '/')
            {
                int j = i + 1;
                if (s[j] == '+' || s[j] == '-')
                    j++;
                while (j < s.size() && isdigit(s[j]))
                    ++j;
                // cout << s.substr(i+1, j-i-1) <<endl;
                int num = stoi(s.substr(i + 1, j - i - 1));
                if (ch == '*')
                    nums.top() *= num;
                else
                    nums.top() /= num;
                i = j - 1;
            }
        }

        int res = 0;
        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};

//      "2*(5+5*2)/3+(6/2+8)"