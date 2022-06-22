class Solution
{
public:
    int calculate(string s)
    {
        // prerocessing
        string s_ = "+";
        for (auto ch : s)
        {
            if (ch == ' ')
                continue;
            s_.push_back(ch);
            if (ch == '(')
                s_.push_back('+');
        }

        stack<int> nums;
        stack<int> sign; // only contains 1/-1
        int sum = 0;
        for (int i = 0; i < s_.size(); ++i)
        {
            if (s_[i] == '(')
            {
                nums.push(sum);
                sum = 0;
            }
            else if (s_[i] == '+' || s_[i] == '-')
            {
                if (i + 1 < s_.size() && (s_[i + 1] == '-' || s_[i + 1] == '+'))
                    continue;
                sign.push(s_[i] == '+' ? 1 : -1);
            }
            else if (isdigit(s_[i]))
            {
                int j = i;
                while (j < s_.size() && isdigit(s_[j]))
                {
                    ++j;
                }
                sum += sign.top() * stoi(s_.substr(i, j - i));
                sign.pop();
                i = j - 1;
            }
            else if (s_[i] == ')')
            {
                sum *= sign.top();
                sign.pop();
                sum += nums.top();
                nums.pop();
            }
        }

        return sum;
    }
};

// +1-(+-2)
// sum = -2
// nums: 1
// sign:-1 1
