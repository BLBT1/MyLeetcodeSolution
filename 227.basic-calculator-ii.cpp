/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        string s_ = "+";
        for (auto ch : s)
        {
            if (ch != ' ')
            {
                s_.push_back(ch);
                if (ch == '(')
                    s_ += "+";
            }
        }

        stack<int> nums;

        for (int i = 0; i < s_.size(); i++)
        {
            if (s_[i] == '+' || s_[i] == '-')
            {
                int j = i + 1;
                while (j < s_.size() && isdigit(s_[j]))
                    j++;
                int num = stoi(s_.substr(i + 1, j - i - 1));
                if (s_[i] == '+')
                    nums.push(num);
                else if (s_[i] == '-')
                    nums.push(-num);
                i = j - 1;
            }
            else if (s_[i] == '*' || s_[i] == '/')
            {
                int j = i + 1;
                while (j < s_.size() && isdigit(s_[j]))
                    j++;
                int num = stoi(s_.substr(i + 1, j - i - 1));
                if (s_[i] == '*')
                    nums.top() *= num;
                else if (s_[i] == '/')
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
// @lc code=end
