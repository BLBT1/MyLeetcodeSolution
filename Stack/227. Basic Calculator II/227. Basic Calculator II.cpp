class Solution
{
public:
    int calculate(string s)
    {
        // preprocess string
        string s_ = "+";
        for (auto ch : s)
        {
            if (ch == ' ')
                continue;
            s_.push_back(ch);
        }

        stack<int> nums;
        for (int i = 0; i < s_.size(); ++i)
        {
            char ch = s_[i];
            if (ch == '+' || ch == '-')
            {
                int j = i + 1;
                while (j < s_.size() && isdigit(s_[j]))
                    ++j;
                int num = stoi(s_.substr(i + 1, j - i - 1));
                if (ch == '+')
                    nums.push(num);
                else
                    nums.push(-num);
                i = j - 1;
            }
            else if (ch == '*' || ch == '/')
            {
                int j = i + 1;
                while (j < s_.size() && isdigit(s_[j]))
                    ++j;
                int num = stoi(s_.substr(i + 1, j - i - 1));
                if (ch == '*')
                    nums.top() *= num;
                else
                    nums.top() /= num;
                i = j - 1;
            }
        }

        int sum = 0;
        while (!nums.empty())
        {
            sum += nums.top();
            nums.pop();
        }
        return sum;
    }
};

// +3+ 5/2
//