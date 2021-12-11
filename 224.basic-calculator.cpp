/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        // preprocess to make a new string
        // get add one extra '+' after all '(' and also the very beginning
        // also get rid of all spaces
        //ex3 should turn to be
        //"+(+1+(+4+5+2)-3)+(+6+8)"
        string s_ = "+";
        for (char ch : s)
        {
            if (ch != ' ')
            {
                s_.push_back(ch);
                if (ch == '(')
                    s_.push_back('+');
            }
        } //for

        stack<int> nums;
        stack<int> signs;
        int sign = 1; // 1 for + and -1 for -
        int sum = 0;  // the partial sum
        for (int i = 0; i < s_.size(); ++i)
        {
            if (s_[i] == '+')
            {
                sign = 1;
            }
            else if (s_[i] == '-')
            {
                sign = -1;
            }
            else if (isdigit(s_[i]))
            {
                // get the entire num
                int this_num = 0;
                int j = i;
                while (i < s_.size() && isdigit(s_[i]))
                {
                    ++i;
                } // while
                this_num = stoi(s_.substr(j, i - j));
                sum += this_num * sign;
                // now i is at the one after the last digit
                --i;
            }
            else if (s_[i] == '(')
            {
                nums.push(sum);
                sum = 0;
                signs.push(sign);
            }
            else if (s_[i] == ')')
            {
                sum = signs.top() * sum;
                signs.pop();
                sum = nums.top() + sum;
                nums.pop();
            }
        } // for

        return sum;
    }
};
// @lc code=end
